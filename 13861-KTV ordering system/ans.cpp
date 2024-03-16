#include <bits/stdc++.h>
#include "function.h"
using namespace std;
const int NN = 1e6 + 5;
bool added[NN], inserted[NN], played[NN];
song *add[NN];

void ordering_system::initialize(){
    memset(added, 0, sizeof(added));
    memset(inserted, 0, sizeof(inserted));
    memset(played, 0, sizeof(inserted));
    this -> head = this -> tmp1 = this -> tmp2 = new song;
    this -> head -> pre = this -> head -> next = this -> head;
    this -> head -> num = -1;
}

void ordering_system::order(int k){
    auto &head = this -> head;
    auto &tmp1 = this -> tmp1;
    auto &tmp2 = this -> tmp2;
    song *now = new song;
    now -> num = k;
    if(added[k]){
        cout << k << "gg\n";
        exit(0);
    }
    add[k] = now;
    added[k] = 1;
    now -> next = head;
    now -> pre = head -> pre;
    head -> pre -> next = now;
    head -> pre = now;
    if(tmp1 == head) tmp1 = tmp2 = now;
    else if(tmp2 == head) tmp2 = now;
}

void ordering_system::show(){
    auto &head = this -> head;
    auto &tmp1 = this -> tmp1;
    if(head -> next != tmp1){
//        cout << " " << head -> next -> num << ' ' << tmp1 -> num << endl;
//        cout << "played: ";
        print(head -> next, tmp1);
    }else cout << endl;
    if(tmp1 != head){
//        cout << "unplay: ";
        print(tmp1, head);
    }else cout << endl;
}

void ordering_system::play(){
    auto &head = this -> head;
    auto &tmp1 = this -> tmp1;
    auto &tmp2 = this -> tmp2;
    if(tmp1 == head){
        cout << "All songs are played.\n";
        return;
    }
    cout << tmp1 -> num;
//    cout << ' ' << tmp1 -> next -> num;
    cout << endl;
    played[tmp1 -> num] = 1;
    if(tmp1 == tmp2){ 
        tmp1 = tmp2 = tmp1 -> next;
    }else{
        tmp1 = tmp1 -> next;
    }
}
void ordering_system::insert(int k){
    auto &tmp1 = this -> tmp1;
    auto &tmp2 = this -> tmp2;
    if(played[k]){
        cout << "gg insert\n";
        exit(0);
    }
    if(!inserted[k]){
        song *now;
        if(!added[k]){
            now = new song;
            add[k] = now;
            now -> num = k;
        }else{
            now = add[k];
            auto &pre = now -> pre;
            auto &next = now -> next;
            pre -> next = next;
            next -> pre = pre;
        }
        added[k] = 1;
        inserted[k] = 1;
        now -> next = tmp2;
        now -> pre = tmp2 -> pre;
        tmp2 -> pre -> next = now;
        tmp2 -> pre = now;
        if(tmp1 == tmp2){
            tmp1 = now;
        }
    }else{
        auto &now = add[k];
        auto &pre = now -> pre;
        auto &next = now -> next;
        if(now == tmp1)
            return;
        pre -> next = next;
        next -> pre = pre;

        now -> next = tmp1;
        now -> pre = tmp1 -> pre;
        tmp1 -> pre -> next = now;
        tmp1 -> pre = now;
        tmp1 = now;
    }

}
void ordering_system::destroy(){
    auto head = this -> head;
    auto now = head -> next;
    while(now != head){
        auto del = now;
        now = now -> next;
        free(del);
    }
    free(head);
}
