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

const ll mod = 1e9;
const ll inf = 1LL << 60;
const int NN = 2e5+5;

int n, m, k;

void solve(){
    cin >> n;
    srand(time(0));
    cout << n << endl;
    while(n--){
        int op, k, x;
        op = rand() % 5 + 1;
        k = rand() % mod;
        x = rand() % mod;
        if(op < 3)
            cout << op << ' ' << k << ' ' << x << endl;
        else if(op == 3)
            cout << op << ' ' << x << endl;
        else
            cout << op << endl;
    }
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--)
        solve();
    return 0;
}

