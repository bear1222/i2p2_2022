#include "function.h"

void Password::addleft(int k){
    node *now = new node;
    now -> val = k;
    this -> now -> left -> right = now;
    now -> left = this -> now -> left;
    this -> now -> left = now;
    now -> right = this -> now;
    this -> now = now;
}

void Password::addright(int k){
    node *now = new node;
    now -> val = k;
    this -> now -> right -> left = now;
    now -> right = this -> now -> right;
    this -> now -> right = now;
    now -> left = this -> now;
    this -> now = now;
}

void Password::toleft(){
    this -> now = this -> head -> right;
}

void Password::toright(){
    this -> now = this -> head -> left;
}

