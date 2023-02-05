#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()
#define sz(v) (int)v.size()

#define MOO(i, a, b) for(int i=a; i<b; i++)
#define M00(i, a) for(int i=0; i<a; i++)
#define MOOd(i,a,b) for(int i = (b)-1; i >= a; i--)
#define M00d(i,a) for(int i = (a)-1; i>=0; i--)

#define FAST ios::sync_with_stdio(0); cin.tie(0);
#define finish(x) return cout << x << '\n', 0;
#define dbg(x) cerr << ">>> " << #x << " = " << x << "\n";
#define _ << " _ " <<

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ld,ld> pd;
typedef complex<ld> cd;

vi adj[200005];
int depth[200005];

void dfs(int v, int p) {
    depth[v] = 1;
    for (int u : adj[v]) {
        if (u == p) continue;
        dfs(u, v);
        depth[v] = max(depth[v], depth[u] + 1);
    }
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) adj[i].clear();
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    dfs(1, -1);
    
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += depth[i];
    }
    for (int i = 0; i < n-1; i++) {
        ans = (ans * 2) % 1000000007LL;
    }
    cout << ans << endl;
}

int main() { FAST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
