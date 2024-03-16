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
vector<int> a;

void dfs(int l, int r){
    if(r <= l) return;
//    cout << l << ',' << r << endl;
    int k = lower_bound(a.begin() + l + 1, a.begin() + r, a[l]) - a.begin();
//    int k = r;
//    for(int i = l + 1; i < r; i++){
//        if(a[i] > a[l]){
//            k = i;
//            break;
//        }
//    }
    dfs(l + 1, k);
    dfs(k, r);
    cout << a[l] << ' ';
}

void solve(){
    cin >> n;
    a.resize(n);
    for(int &i : a) cin >> i;
    dfs(0, n);
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--)
        solve();
    return 0;
}

