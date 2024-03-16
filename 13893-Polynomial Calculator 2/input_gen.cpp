#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
typedef pair<int,int> pii;
#define X first
#define Y second
#define pb push_back
#define All(a) a.begin(), a.end()
#define SZ(a) ((int)a.size())
#define endl '\n'
#define yn(ok) cout << (ok ? "Yes" : "No") << endl;

const ll mod = 1e9+7;
const ll inf = 1LL << 60;
const int NN = 2e5+5;

int n, m, k;
string op[10] = {"+", "-", "*", "/", "**", "sin", "cos"};
int xnum = 0;

double randnum(){
    double x = rand() % 20000 + 1;
    x /= 100;
    x -= 100;
    return x;
}

void gen(int k){
    if(k == 0){
        int xx = rand() % 8;
        if(!xnum || !xx){
            cout << "x ";
            xnum = 1;
            return;
        }
        double x = randnum();
        cout << fixed << setprecision(2) << x << ' ';
//        int x = rand() % 100 + 1;
//        cout << x << ' ';
        return;
    }
    int t = rand() % 7;
    cout << op[t] << ' ';
//    cout << endl;
    if(t >= 4){
        gen(k - 1 - (t == 4));
        double x = randnum();
        if(t == 4)
            cout << fixed << setprecision(2) << x << ' ';
//        int x = rand() % 100 + 1;
//        if(t == 4) 
//            cout << x << ' ';
        return;
    }
    if(k == 1){
        gen(0); gen(0);
        return;
    }
    int tmp = rand() % (k - 1);
//    cout << k << ' ';
//    cout << tmp << ' ' << k - 1 - tmp << endl;
    gen(tmp);
    gen(k - 1 - tmp);
}

void solve(){
    int n, q;
    cin >> n >> q;
    gen(n);
    cout << endl;
    cout << q << endl;
    while(q--){
        double x = rand() % 10000 + 1;
        x /= 100;
        cout << x << endl;
    }
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    while(t--)
        solve();
    return 0;
}

