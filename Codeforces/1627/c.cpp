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

vector<pi> adj[100005];
int ans[100005];

void dfs(int v, int p, int w) {
	for (pi u : adj[v]) {
		if (u.f != p) {
			ans[u.s] = w;
			dfs(u.f, v, 5-w);
		}
	}
}

int main() { FAST
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 1; i<=n; i++) {
			adj[i].clear();
		}
		int u, v;
		for (int i = 0; i<n-1; i++) {
			cin >> u >> v;
			adj[u].pb(mp(v,i));
			adj[v].pb(mp(u,i));
		}
		bool bad = false;
		for (int i = 1; i<=n; i++) {
			if (sz(adj[i]) > 2)
				bad = true;
		}
		if (bad) {
			cout << "-1\n";
			continue;
		}
		ans[n-2] = 2;
		dfs(u, v, 3);
		dfs(v, u, 3);
		for (int i = 0; i<n-1; i++) {
			cout << ans[i] << " ";
		}
		cout << "\n";
	}
}
