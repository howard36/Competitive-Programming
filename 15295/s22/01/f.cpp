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

int n, m;

vector<pi> adj[100005];
int vis[100005], vis2[100005], ans[2], sol[2][100005];
int ccsz, ccans;

bool dfs(int v, int par, int c, int t) {
	if (vis[v])
		return sol[t][v] == c;
	vis[v] = true;
	ccsz++;
	sol[t][v] = c;
	ccans += c;
	for (pi p : adj[v]) {
		if (p.f != par) {
			if (!dfs(p.f, v, c^p.s^t, t)) {
				return false;
			}
		}
	}
	return true;
}

void flip(int v, int par, int t) {
	sol[t][v] ^= 1;
	vis2[v] = true;
	for (pi p : adj[v]) {
		if (p.f != par && !vis2[p.f])
			flip(p.f, v, t);
	}
}

void solve(int t) {
	memset(vis, 0, sizeof(vis));
	memset(vis2, 0, sizeof(vis2));
	for (int i = 1; i<=n; i++) {
		if (!vis[i]) {
			ccsz = 0, ccans = 0;
			if (!dfs(i, -1, 0, t)) {
				ans[t] = 1e9;
				return;
			}
			if (2*ccans > ccsz) {
				flip(i, -1, t);
				ans[t] += ccsz - ccans;
			} else {
				ans[t] += ccans;
			}
		}
	}
}


int main() { FAST
	cin >> n >> m;
	for (int i = 0; i<m; i++) {
		int x, y;
		char c;
		cin >> x >> y >> c;
		int w = (c == 'R');
		adj[x].pb(mp(y,w));
		adj[y].pb(mp(x,w));
	}
	solve(0);
	solve(1);
	int t = ans[0] < ans[1] ? 0 : 1;
	if (ans[t] == 1e9) {
		finish(-1);
	} else {
		cout << ans[t] << "\n";
		for (int i = 1; i<=n; i++)
			if (sol[t][i])
				cout << i << " ";
	}
}
