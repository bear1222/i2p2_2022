#include <iostream>
#include <cstdlib>
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

void solve(){
    int n;
    cin >> n;
    ordering_system os;
    os.initialize();
    int show = 0;
    while(n--){
        string op;
        int x;
        cin >> op;
//        cout << op << ' ';
        if(op == "order"){
            cin >> x;
//            cout << x << endl;
            os.order(x);
        }else if(op == "insert"){
            cin >> x;
//            cout << x << endl;
            os.insert(x);
        }else if(op == "play"){
//            cout << endl;
            os.play();
        }else{
//            cout << endl;
            show++;
            if(show > 200){
                cout << "gg\n";
                exit(0);
            }
            os.show();
        }
    }
    os.destroy();
}

signed main(){
    //ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}

