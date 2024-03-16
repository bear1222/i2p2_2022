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
const int NN = 2e6+5;

int n, m, k;

int rand(int a, int b){
    int d = b - a + 1;
    int tmp = rand() % d;
    return tmp + a;
}

signed main(){
//    ios_base::sync_with_stdio(false); cin.tie(0);
    srand(time(0));
    cin >> n >> k;
    cout << n << endl;
    for(int i = 0; i < n; i++){
        int x = rand(0, k);
        cout << x << " \n"[i == n - 1];
    }
    return 0;
}

