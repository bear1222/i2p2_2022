#include <iostream>
#include <cstdlib>
using namespace std;

struct node{
    int val;
    node *left, *right;
};

class Password{
    private:
        node *head, *now;
    public:
        Password(){
            this -> head = new node;
            this -> now = head;
            this -> head -> right = this -> head -> left = this -> head;
            this -> addright(0);
        }
        void addleft(int k);
        void addright(int k);
        void toleft();
        void toright();
        void print(){
            node *now = this -> head -> right;
            while(now != head){
                cout << now -> val << ' ';
                now = now -> right;
            }
            cout << endl;
        }
        void byebye(){
            node *now = this -> head -> right;
            while(now != head){
                node *del = now;
                now = now -> right;
                free(del);
            }
            free(this -> head);
        }
};

