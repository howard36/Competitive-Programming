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

vector<int> adj[300005];
ll dp[300005];
const ll M = 1000000007;
bool vis[300005];
int depth[300005];
vector<int> lengths;

void dfs(int v, int p, int d) {
	depth[v] = d;
	vis[v] = true;
	for (int i = 0; i<adj[v].size(); i++) {
		int u = adj[v][i];
		if (u != p) {
			if (vis[u])
				lengths.pb(depth[v] - depth[u]);
			else
				dfs(u, v, d+1);
		}
	}
}

int main() { FAST
	int z;
	cin >> z;
	while (z--) {
		int n, m, a, b;
		ll k;
		cin >> n >> m >> k;
		for (int i = 0; i<n; i++)
			adj[i].clear();
		for (int i = 0; i<m; i++) {
			cin >> a >> b;
			a--, b--;
			adj[a].pb(b);
			adj[b].pb(a);
		}
		dp[0] = 1, dp[1] = 0;
		for (int i = 2; i<=n; i++) {
			dp[i] = ((k-1) * dp[i-2] % M + (k-2) * dp[i-1] % M) % M;
		}
		for (int i = 0; i<n; i++)
			vis[i] = false;
		lengths.clear();
		dfs(0, -1, 0);
		ll ans = k;
		int leftover = n-1;
		for (int i = 0; i<lengths.size(); i++) {
			int l = lengths[i];
			if (l < 0) continue;
			ans = ans * dp[l+1] % M;
			leftover -= l;
		}
		for (int i = 0; i<leftover; i++) {
			ans = ans * (k-1) % M;
		}
		cout << (ans % M + M) % M << "\n";
	}
}
