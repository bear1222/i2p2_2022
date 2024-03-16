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

struct node{
    int num;
    node *l, *r;
    node(){}
    node(int k): num(k), l(NULL), r(NULL) {}
}*root;

void add(int k){
    node *now = root, *tmp = new node(k);
    while(1){
        if(k > now -> num){ // right
            if(now -> r == NULL){
                now -> r = tmp;
                return;
            }
            now = now -> r; 
        }else{
            if(now -> l == NULL){
                now -> l = tmp;
                return;
            }
            now = now -> l;
        }
    }
}

void dfs(node *now){
    if(now == NULL) return;
    cout << now -> num << ' ';
    dfs(now -> l);
    dfs(now -> r);
}

int n, m, k;

void solve(){
    srand(time(0));
    cin >> n;
    cout << n << endl;
    root = new node;
    root -> num = -1;
    set<int> s;
    for(int i = 0; i < n; i++){
        int k = rand() % (mod - 7) + 1;
        while(s.find(k) != s.end())
            k = rand() % (mod - 7) + 1;
        s.insert(k);
        add(k);
    }
    dfs(root -> r);
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
//    cin >> t;
    while(t--)
        solve();
    return 0;
}

