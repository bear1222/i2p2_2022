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

class Box{
    public:
    int qmax(){
        if(mp.empty()) return -2 * mod;
        return mp.rbegin() -> X;
    }
    int qmin(){
        if(mp.empty()) return -2 * mod;
        return mp.begin() -> X;
    }
    pii qmost(){
        if(mp.empty()) return {-1, -1};
        return {s.rbegin() -> Y, s.rbegin() -> X};
    }
    void add(int k, int x){
        s.erase({mp[x], x});
        mp[x] += k;
        s.insert({mp[x], x});
    }
    void remove(int k, int x){
        s.erase({mp[x], x});
        mp[x] -= k;
        if(mp[x] <= 0) mp.erase(x);
        else s.insert({mp[x], x});
    }
    int qx(int x){
        if(mp.find(x) == mp.end()) return 0;
        return mp[x];
    }
    private:
    map<int, int> mp;
    set<pii> s;
}box;

void solve(){
    cin >> n;
    srand(time(0));
    cout << n << endl;
    cout << "1 5 2\n3 1\n5\n";
    box.add(5, 2);
    n -= 3;
    while(n--){
        int op, k, x;
        op = rand() % 6 + 1;
        k = rand() % mod;
        x = rand() % mod;
        if(op == 1){
            cout << op << ' ' << k << ' ' << x << endl;
            box.add(k, x);
        }else if(op == 2){
            auto [num, most] = box.qmost();
            box.remove(most, num);
            auto [num2, most2] = box.qmost();
            if(most != -1){
                k = num;
                if(most2 != -1)
                    x = most - most2 + 1;
            }
            box.add(most, num);

            cout << op << ' ' << k << ' ' << x << endl;
            box.remove(k, x);

        }else if(op == 3){
            cout << op << ' ' << x << endl;
        }else if(op == 4){
            cout << op << endl;
        }else if(op == 5){
            cout << op << endl;
        }else{
            cout << op << endl;
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

