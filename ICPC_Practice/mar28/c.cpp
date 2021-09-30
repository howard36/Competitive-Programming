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
#define dbg(x) // cerr << ">>> " << #x << " = " << x << "\n";
#define _ << " _ " <<

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ld,ld> pd;
typedef complex<ld> cd;


template<int SZ> struct Dinic {
	typedef ll F; // flow type
	struct Edge { int to, rev; F flow, cap; };
	
	int N,s,t;
	vector<Edge> adj[SZ];
	typename vector<Edge>::iterator cur[SZ];
	void addEdge(int u, int v, F cap) {
		assert(cap >= 0); // don't try smth dumb
		Edge a{v, sz(adj[v]), 0, cap}, b{u, sz(adj[u]), 0, 0};
		adj[u].pb(a), adj[v].pb(b);
	}

	int level[SZ];
	bool bfs() { // level = shortest distance from source
		// after computing flow, edges {u,v} such that level[u] \neq -1, level[v] = -1 are part of min cut
		M00(i,N) level[i] = -1, cur[i] = begin(adj[i]);
		queue<int> q({s}); level[s] = 0; 
		while (sz(q)) {
			int u = q.front(); q.pop();
            for(Edge e: adj[u]) if (level[e.to] < 0 && e.flow < e.cap)
				q.push(e.to), level[e.to] = level[u]+1;
		}
		return level[t] >= 0;
	}
	F sendFlow(int v, F flow) {
		if (v == t) return flow;
		for (; cur[v] != end(adj[v]); cur[v]++) {
			Edge& e = *cur[v];
			if (level[e.to] != level[v]+1 || e.flow == e.cap) continue;
			auto df = sendFlow(e.to,min(flow,e.cap-e.flow));
			if (df) { // saturated at least one edge
				e.flow += df; adj[e.to][e.rev].flow -= df;
				return df;
			}
		}
		return 0;
	}
	F maxFlow(int _N, int _s, int _t) {
		N = _N, s = _s, t = _t; if (s == t) return -1;
		F tot = 0;
		while (bfs()) while (auto df = sendFlow(s,numeric_limits<F>::max())) tot += df;
		return tot;
	}
    void p(int i, int j) {
        bool found = false;
        dbg(i _ j);
        for (Edge e : adj[j]) {
            dbg(j _ e.to _ e.flow);
            if (e.flow > 0 && e.to != i) {
                found = true;
                cout << j << " " << e.to << "\n";
            }
        }
        if (!found)
            cout << j << " -1\n";
    }
};

vi adj[1003];
int vis[1003], par[1003];

int main() { FAST
	int n, m;
    cin >> n >> m;
    for (int i = 0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    bool possible = false;
    for (int i = 1; i<=n; i++) {
        Dinic<1003> D;
        for (int j = 1; j<=n; j++)
            vis[j] = 0;
        vis[i] = 1;
        for (int j : adj[i]) {
            vis[j] = 1;
            D.addEdge(i, j, 1);
        }
        for (int j : adj[i]) {
            for (int k : adj[j]) {
                if (!vis[k]) {
                    D.addEdge(j, k, 1);
                }
            }
        }
        int cnt = 0;
        for (int k = 1; k<=n; k++) {
            if (!vis[k]) {
                D.addEdge(k, 0, 1);
                cnt++;
            }
        }
        dbg(cnt);
        if (cnt == D.maxFlow(n+1, i, 0)) {
            possible = true;
            dbg(i);
            cout << "Yes\n" << i << " " << sz(adj[i]) << "\n";
            for (int j : adj[i])
                D.p(i, j);
            return 0;
        }
    }
    if (!possible)
        cout << "No\n";
}
