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
vector<int> g[NN], p;

vector<int> deg, dep;
int mxdeg = 0, mxdep = 0;

void dfs(int k, int pp){
    p[k] = pp;
    dep[k] = dep[pp] + 1;
    for(int nt : g[k]){
        if(nt != pp){
            deg[k]++;
            dfs(nt, k);
        }
    }
    mxdeg = max(mxdeg, deg[k]);
    mxdep = max(mxdep, dep[k]);
}

void solve(){
    cin >> n >> m;
    p.resize(n);
    dep.resize(n);
    deg.resize(n);
    for(int i = 0; i < n - 1; i++){
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    dfs(0, 0);

    for(int i = 0; i < n; i++){
        if(deg[i] > 100 || dep[i] > 1000){
            cout << "gg on " << i << "\n";
            exit(0);
        }
    }
    cout << mxdeg << ' ' << mxdep << endl;
    return;

    while(m--){
        cin >> k;
        vector<int> ans;
        ans.pb(k);
        while(k != 0){
            k = p[k];
            ans.pb(k);
        }
        reverse(All(ans));
        int len = SZ(ans);
//        for(int i = 0; i < len; i++){
//            cout << ans[i] << " \n"[i == len - 1];
//        }
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

