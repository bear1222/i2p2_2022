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
const int NN = 2e6+5;

int n, m, k;

struct DJS{
  vector<int> p;
  DJS(int n){ 
    p.resize(n + 1);
    for(int i = 0; i <= n; i++) p[i] = i; 
  }
  int fd(int k){ 
    return p[k] == k ? k : p[k] = fd(p[k]); 
  }
  bool same(int a, int b){ 
    return fd(a) == fd(b); 
  }
  void join(int a, int b){
    a = fd(a), b = fd(b);
    p[b] = a;
  }
};

struct edge {
  int u, v, cost;
  bool operator<(const edge &other) const {
    return cost < other.cost;
  }
};

vector<edge> ee;

vector<edge> mst(int n) {
  sort(ee.begin(), ee.end());
  DJS djs(n);
  vector<edge> ans;
  int cnt = 0;
  for (auto &e : ee) {
    if (djs.same(e.u, e.v)) continue;
    djs.join(e.u, e.v);
    ans.pb(e);
    ++cnt;
  }
  if (cnt < n - 1) cout << "gg\n";
  return ans;
}

int rand(int a, int b){
    int d = b - a + 1;
    int tmp = rand() % d;
    return tmp + a;
}

signed main(){
//    ios_base::sync_with_stdio(false); cin.tie(0);
    srand(time(0));
    cin >> n >> m;
    set<pii> existedge;
    int edgemx = min(NN * 10, n * (n - 1) / 2);
    for(int i = 0; i < n; i++){
        int w = rand(1, mod);
        int u = i, v = (i + 1) % n;
        if(u > v) swap(v, u);
        existedge.insert({u, v});
        ee.pb({u, v, w});
        existedge.insert({u, u});
    }
//    for(auto [u, v] : existedge){
//        cout << u << ' ' << v << endl;
//    }cout << endl;
    edgemx -= n;
    while(edgemx--){
        int u = rand(0, n - 1), v = rand(0, n - 1);
        if(u > v) swap(u, v);
        while(existedge.find({u, v}) != existedge.end()){
            u = rand(0, n - 1), v = rand(0, n - 1);
            if(u > v) swap(u, v);
        }
        int w = rand(1, mod);
        existedge.insert({u, v});
        ee.pb({u, v, w});
    }
//    for(auto [u, v, w] : ee){
//        cout << u << ' ' << v << endl;
//    }
//    cout << endl;
    vector<edge> ans = mst(n);
    cout << n << ' ' << m << endl;
    for(auto [u, v, w] : ans){
        cout << u << ' ' << v << endl;
    }
    set<int> qexist;
    vector<int> qq;
    for(int i = 0; i < m; i++){
        int x = rand(1, n - 1);
        while(qexist.find(x) != qexist.end()){
            x = rand(1, n - 1);
        }
        cout << x << " \n"[i == m - 1];
        qexist.insert(x);
    }
    return 0;
}

