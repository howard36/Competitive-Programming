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
#define F0R(i, a) for(int i=0; i<a; i++)
#define MOOd(i,a,b) for(int i = (b)-1; i >= a; i--)
#define M00d(i,a) for(int i = (a)-1; i>=0; i--)
#define trav(i,v) for(int i : (v))

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

template<int SZ> struct SCC {
    int N, comp[SZ];
    vi adj[SZ], radj[SZ], todo, allComp;
    bitset<SZ> visit;
    void addEdge(int a, int b) { adj[a].pb(b), radj[b].pb(a); }
    void dfs(int v) {
        visit[v] = 1;
        trav(w,adj[v]) if (!visit[w]) dfs(w);
        todo.pb(v);
    }
    void dfs2(int v, int val) {
        comp[v] = val;
        trav(w,radj[v]) if (comp[w] == -1) dfs2(w,val);
    }
    void init(int _N) { // fills allComp
        N = _N;
        F0R(i,N) comp[i] = -1, visit[i] = 0;
        F0R(i,N) if (!visit[i]) dfs(i);
        reverse(all(todo)); // now todo stores vertices in order of topological sort
        trav(i,todo) if (comp[i] == -1) dfs2(i,allComp.size()), allComp.pb(i);
    }
    void clear(int n) {
        for (int i = 1; i <= n; i++) {
            adj[i].clear();
            radj[i].clear();
        }
        memset(comp, 0, sizeof(comp));
        todo.clear();
        allComp.clear();
    }
};

set<int> adj[200005], radj[200005];
int col[200005];
bool top[200005];
int ntop;
vector<pair<int,pi>> edges;
SCC<200005> S;

void dfs(int v, int c) {
    col[v] = c;
    for (int u : adj[v]) {
        if (col[u] == 0) dfs(u, c);
        else if (col[u] == c) continue;
        else top[col[u]] = false;
    }
}

int solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) adj[i].clear();
    memset(col, 0, sizeof(col));
    memset(top, 0, sizeof(top));
    ntop = 0;
    edges.clear();
    S.clear(n);

    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        edges.pb(mp(w,mp(a,b)));
        adj[a].pb(b);
        S.addEdge(a, b);
    }
    S.init(n);

    int c = S.allComp.size();
    for (auto e : edges) {
        int a = e.s.f, b = e.s.s;
        int ca = S.comp[a];
        int cb = S.comp[b];
        adj[ca].insert(cb);
        radj[cb].insert(ca);
    }

    sort(all(edges));
    for (auto e : edges) {
        int a = e.s.f, b = e.s.s;
        int ca = S.comp[a];
        int cb = S.comp[b];
        adj[cb].insert(ca);
        if (vis[b] && !vis[a]) dfs(a);
        if (nvis == n) return e.f;
    }
    return -1;
}

int main() { FAST
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << endl;
    }
}
