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
    cout << n << endl;
    for(int i = 0; i < n; i++)
        cout << rand() % mod << ' ';
    cout << endl;
}

signed main(){
//    ios_base::sync_with_stdio(false); cin.tie(0);
    srand(time(0));
    int t = 1;
    cin >> t >> n;
//    cout << t << endl;
    while(t--)
        solve();
    return 0;
}

