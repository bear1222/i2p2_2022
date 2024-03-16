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

void solve(){
    cin >> n;
    vector<int> a(n);
    for(auto &i : a) cin >> i;
    stack<pii> s;
    s.push({mod, -1});
    for(int i = 0; i < n; i++){
        while(!s.empty() && s.top().X <= a[i])
            s.pop();
        cout << s.top().Y + 1 << ' ';
        s.push({a[i], i});
    }
    cout << endl;
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
//    cin >> t;
    while(t--)
        solve();
    return 0;
}

