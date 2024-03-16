#include <iostream>
#include "function.h"
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t, n, m;
    cin >> t;
    while(t--){
        Password pw;
        string s; cin >> s;
        int x = 1, m = s.size();
        for(int i = 0; i < m; i++){
            char op = s[i];
            if(op == 'L')
                pw.addleft(x++);
            else if(op == 'R')
                pw.addright(x++);
            else if(op == 'l')
                pw.toleft();
            else
                pw.toright();
        }
        pw.print();
        pw.byebye();
    }
    return 0;
}

