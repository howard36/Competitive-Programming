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
#define dbg(x) //cerr << ">>> " << #x << " = " << x << "\n";
#define _ << " _ " <<

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ld,ld> pd;
typedef complex<ld> cd;

vector<pi> adj[10003];
int visited[10003], par[10003], parcol[10004];
int ncycles;

template<int SZ> struct Dinic {
	typedef ll F; // flow type
	struct Edge { int to, rev; F flow, cap; };
	int N,s,t;
	vector<Edge> adj[SZ];
	typename vector<Edge>::iterator cur[SZ];
	void addEdge(int u, int v, F cap) {
		dbg("EDGE" _ u _ v _ cap)
		assert(cap >= 0); // don’t try smth dumb

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
			if (level[e.to] != level[v]+1 || e.flow == e.cap)
				continue;
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
};

struct Dinic<20005> D;

int colcnt[10004];
int n, m;

set<pi> incycle;

void dfs(int v, int p, int col, int time) {
	dbg(v _ p _ col)
	if (visited[v]) { // loop
		dbg("loop" _ v)
		ncycles++;
		D.addEdge(ncycles, m+1+col, 1);
		int len = 1;
		colcnt[col]++;
		dbg(col)
		incycle.insert(mp(v, p));
		for (int i = p; i != v; i = par[i]) {
			D.addEdge(ncycles, m+1+parcol[i], 1);
			incycle.insert(mp(i, par[i]));
			colcnt[parcol[i]]++;
			len++;
			dbg(i _ parcol[i])
			if (i == 0) {
				dbg("BAD")
				return;
			}
		}
		dbg(len)
		D.addEdge(0, ncycles, len-1);
		return;
	}
	visited[v] = time;
	par[v] = p;
	parcol[v] = col;
	dbg("searching" _ v)
	for (pi u : adj[v]) {
		if (u.f == p) continue;
		if (visited[u.s] < time)
			dfs(u.f, v, u.s, time+1);
	}
}

int main() { FAST
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, col;
		cin >> a >> b >> col;
		adj[a].pb(pi(b, col));
		adj[b].pb(pi(a, col));
	}
	dfs(1, -1, -1, 1);
	for (int i = 1; i <= m; i++) {
		D.addEdge(m+i+1, 2*m+2, 1);
	}
	for (int i = 1; i<=n; i++) {
		for (pi j : adj[i]) {
			if (i < j.f) continue;
			if (incycle.find(pi(i,j.f)) == incycle.end() && incycle.find(pi(j.f,i)) == incycle.end()) {
				D.addEdge(0, m+1+j.s, 1);
			}
		}
	}
	finish(D.maxFlow(2*m+3, 0, 2*m+2));

}
