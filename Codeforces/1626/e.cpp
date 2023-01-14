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

int b[300005], s[300005], c[300005], vis[300005];
int B;
vector<int> adj[300005], adj2[300005];

void dfs(int v, int p) {
	for (int u : adj[v]) {
		if (u != p) {
			dfs(u, v);
			s[v] += s[u];
		}
	}
	if (p < 0)
		return;
	if (s[v] > 1)
		adj2[v].pb(p);
	if (s[v] < B-1)
		adj2[p].pb(v);
}

void dfs2(int v, int p) {
	vis[v] = 1;
	for (int u : adj2[v]) {
		if (u != p && !vis[u])
			dfs2(u, v);
	}
}

int main() { FAST
	int n;
	cin >> n;
	for (int i = 0; i<n; i++) {
		cin >> b[i];
		s[i] = b[i];
		B += b[i];
	}
	for (int i = 0; i<n-1; i++) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	dfs(0, -1);
	for (int i = 0; i<n; i++) {
		if (b[i]) {
			c[i] = 1;
			for (int v : adj[i])
				c[v] = 1;
		}
	}
	for (int i = 0; i<n; i++) {
		if (c[i])
			adj2[n].pb(i);
	}
	dfs2(n, -1);
	for (int i = 0; i<n; i++) {
		cout << vis[i] << " ";
	}
	cout << endl;
}
