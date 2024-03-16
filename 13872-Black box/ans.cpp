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
    map<int, int> mp;
    while(n--){
        int op, k, x;
        cin >> op;
        if(op == 1){
            cin >> k >> x;
            mp[x] += k;
        }else if(op == 2){
            cin >> k >> x;
            mp[x] -= k;
            if(mp[x] <= 0)
                mp.erase(x);
        }else if(op == 3){
            cin >> x;
            if(mp.find(x) != mp.end())
                cout << mp[x] << endl;
            else cout << 0 << endl;
        }else if(op == 4){
            if(mp.empty()) cout << "The box is empty.\n";
            else cout << mp.rbegin() -> X << endl;
        }else{
            if(mp.empty()) cout << "The box is empty.\n";
            else cout << mp.begin() -> X << endl;
        }
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

