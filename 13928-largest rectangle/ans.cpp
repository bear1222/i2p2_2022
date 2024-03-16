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
    vector<int> a(n), l(n), r(n);
    stack<pii> s; // height, pos
    for(auto &i : a) cin >> i;
    s.push({-1, -1});
    for(int i = 0; i < n; i++){
        while(s.top().X >= a[i]) s.pop();
        l[i] = s.top().Y;
        s.push({a[i], i});
    }
    while(!s.empty()) s.pop();
    s.push({-1, n});
    for(int i = n - 1; i >= 0; i--){
        while(s.top().X >= a[i]) s.pop();
        r[i] = s.top().Y;
        s.push({a[i], i});
    }
//    for(int i : l) cout << i << ' '; cout << endl;
//    for(int i : r) cout << i << ' '; cout << endl;
    int ans = 0;
    for(int i = 0; i < n; i++){
        int wid = r[i] - l[i] - 1, area = wid * a[i];
        ans = max(ans, area);
    }
    cout << ans << endl;
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}

