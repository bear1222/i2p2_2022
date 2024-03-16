#include <iostream>
#include <cstdlib>
#include <bits/stdc++.h>
#include "function.h"
using namespace std;

void print(song *st, song *en){
    song *now = st;
    while(now != en){
        cout << now -> num << ' ';
        now = now -> next;
    }
    cout << "\n";
}

int n, t;
const int NN = 1e6 + 5;
bool added[NN], played[NN], inserted[NN];
//song *add[NN];


bool ordered[int(1e6) + 5];
//bool inserted[int(1e6) + 5];
std::list<int>::iterator pos[int(1e6) + 5];

std::list<int> order_list;
std::list<int> insert_list;
std::list<int> played_list;

void ordering_system::initialize() {
	memset(inserted, 0, sizeof(inserted));
	memset(ordered, 0, sizeof(ordered));
	memset(played, 0, sizeof(ordered));
	order_list.clear();
	insert_list.clear();
	played_list.clear();
}

void ordering_system::order(int k) {
	assert(!ordered[k]);
	pos[k] = order_list.emplace(order_list.end(), k);
	ordered[k] = true;
}

void ordering_system::play() {
	int k = -1;
	if (insert_list.empty()) {
		if (order_list.empty()) {
//			std::cout << "All songs are played." << '\n';
			return;
		} else {
			k = order_list.front();
			order_list.pop_front();
		}
	} else {
		k = insert_list.front();
		insert_list.pop_front();
	}

//	std::cout << k << '\n';
    played[k] = 1;
	pos[k] = played_list.emplace(played_list.end(), k);
	// ordered[k] = inserted[k] = false;
}

void ordering_system::show() {
	for (int k: played_list)
		std::cout << k << ' ';
	std::cout << '\n';

	for (int k: insert_list)
		std::cout << k << ' ';
	for (int k: order_list)
		std::cout << k << ' ';
	std::cout << '\n';
}

void ordering_system::insert(int k) {
	if (ordered[k]) {
		if (inserted[k])
			insert_list.erase(pos[k]);
		else
			order_list.erase(pos[k]);
	}

	pos[k] = insert_list.emplace(
		inserted[k]? insert_list.begin(): insert_list.end(),
		k
	);

	ordered[k] = inserted[k] = true;
}

void ordering_system::destroy() {

}

/*
void ordering_system::initialize(){
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

void ordering_system::play(){
    auto &head = this -> head;
    auto &tmp1 = this -> tmp1;
    auto &tmp2 = this -> tmp2;
    if(tmp1 == head){
//        cout << "All songs are played.\n";
        return;
    }
//    cout << tmp1 -> num << endl;
    played[tmp1 -> num] = 1;
    if(tmp1 == tmp2) tmp1 = tmp2 = tmp1 -> next;
    else tmp1 = tmp1 -> next;
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
void ordering_system::insert(int k){
    auto &tmp1 = this -> tmp1;
    auto &tmp2 = this -> tmp2;
    if(!inserted[k]){
        song *now = new song;
        add[k] = now;
        now -> num = k;
        added[k] = 1;
        inserted[k] = 1;
        now -> next = tmp2;
        now -> pre = tmp2 -> pre;
        tmp2 -> pre -> next = now;
        tmp2 -> pre = now;
        if(tmp1 == tmp2) tmp1 = now;
    }else{
        auto &now = add[k];
        auto &pre = now -> pre;
        auto &next = now -> next;
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
    free(now);
}
*/

string opp[4] = {"order", "insert", "play", "show"};

void solve(){
    memset(added, 0, sizeof(added));
    memset(played, 0, sizeof(played));
    memset(ordered, 0, sizeof(played));
    memset(inserted, 0, sizeof(played));
    ordering_system os;
    os.initialize();
    cout << n << endl;
    int show = 0, pre = -1;
    for(int _ = 0; _ < n - 1; _++){
        int x, k = rand() % 4;
        if(show == 199) k = rand() % 3;
        while(k == 3 && (pre == 3 || _ == n - 2))
            k = rand() % 3;
        pre = k;
        string op = opp[k];
        if(op == "order"){
            x = rand() % (NN - 5);
            while(ordered[x] || played[x]) x = rand() % (NN - 5);
            cout << opp[k] << ' ' << x << endl;
            os.order(x);
            added[x] = 1;
        }else if(op == "insert"){
            x = rand() % (NN - 5);
            while(played[x]) x = rand() % (NN - 5);
            cout << op << ' ' << x << endl;
            os.insert(x);
            inserted[x] = 1;
        }else if(op == "play"){
            cout << op << endl;
            os.play();
        }else{
            show++;
            cout << op << endl;
//            os.show();
        }
//        os.show();
//        cout << "----------\n";
    }
    cout << opp[3] << endl;
    os.destroy();
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    srand(time(0));
    cin >> t >> n;
    cout << t << endl;
    while(t--)
        solve();
    return 0;
}

