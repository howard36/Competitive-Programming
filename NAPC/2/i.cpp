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

template<int SZ> struct Dinic {
	typedef ll F;
	struct Edge { int to, rev; F flow, cap; };
	int N,s,t;
	vector<Edge> adj[SZ];
	typename vector<Edge>::iterator cur[SZ];
	void addEdge(int u, int v, F cap) {
		assert(cap >= 0);
		Edge a{v, sz(adj[v]), 0, cap}, b{u, sz(adj[u]), 0, 0};
		adj[u].pb(a), adj[v].pb(b);
	}
	int level[SZ];
	bool bfs() {
		M00(i, N) level[i] = -1, cur[i] = begin(adj[i]);
		queue<int> q({s}); level[s] = 0;
		while (sz(q)) {
			int u = q.front(); q.pop();
			for (Edge e : adj[u]) if (level[e.to] < 0 && e.flow < e.cap)
				q.push(e.to), level[e.to] = level[u] + 1;
		}
		return level[t] >= 0;
	}
	F sendFlow(int v, F flow) {
		if (v == t) return flow;
		for (; cur[v] != end(adj[v]); cur[v]++) {
			Edge& e = *cur[v];
			if (level[e.to] != level[v] + 1 || e.flow == e.cap)
				continue;
			auto df = sendFlow(e.to, min(flow, e.cap - e.flow));
			if (df) {
				e.flow += df; adj[e.to][e.rev].flow -= df;
				return df;
			}
		}
		return 0;
	}
	F maxFlow(int _N, int _s, int _t) {
		N = _N, s = _s, t = _t; if (s == t) return -1;
		F tot = 0;
		while (bfs()) while (auto df = sendFlow(s, numeric_limits<F>::max())) tot += df;
		return tot;
	}
};

int a[102][102];
Dinic<10004> D;

int main() { FAST
	int n, m;
	cin >> n >> m;
	string s;
	int inv = 0;
	M00(i, n) {
		M00(j, m) {
			cin >> s;
			if (s[0] == 'R') a[i][j] = 1;
			char c = s[1];
			if (c == '^') inv += 0;
			if (c == '>') inv += 1;
			if (c == 'v') inv += 2;
			if (c == '<') inv += 3;
		}
	}
	inv = inv % 4;
	M00(i, n) {
		M00(j, m) {
			if ((i+j)%2 == 0) {
				if (i != n-1 && a[i][j] != a[i+1][j])
					D.addEdge(m*i+j, m*(i+1)+j, 1);
				if (i != 0 && a[i][j] != a[i-1][j])
					D.addEdge(m*i+j, m*(i-1)+j, 1);
				if (j != m-1 && a[i][j] != a[i][j+1])
					D.addEdge(m*i+j, m*i+j+1, 1);
				if (j != 0 && a[i][j] != a[i][j-1])
					D.addEdge(m*i+j, m*i+j-1, 1);
				D.addEdge(m*n, m*i+j, 1);
			}
			else {
				D.addEdge(m*i+j, m*n+1, 1);
			}
		}
	}
	ll flow = D.maxFlow(m*n+2, m*n, m*n+1);
	int par = 0;
	if (n % 2 == 0) par = (n*m) % 4;
	if (2*flow == m*n && inv != par)
		flow--;
	finish(flow);
}
