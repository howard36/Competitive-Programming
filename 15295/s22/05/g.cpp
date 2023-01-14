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

vector<int> adj[200005];
int h[200005], maxst[200005];
ll ans = 0;

void dfs(int v, int p) {
	int max_child = 0;
	for (int u : adj[v]) {
		if (u == p) continue;
		dfs(u, v);
		max_child = max(max_child, maxst[u]);
	}
	maxst[v] = max(h[v], max_child);
	ans += maxst[v] - max_child;
}

int main() { FAST
	int n;
	cin >> n;
	for (int i = 1; i<=n; i++)
		cin >> h[i];
	for (int i = 0; i < n-1; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	int root = 0;
	for (int i = 1; i<=n; i++) {
		if (h[i] > h[root])
			root = i;
	}
	vector<int> maxs;
	for (int i : adj[root]) {
		dfs(i, root);
		maxs.pb(maxst[i]);
	}
	maxs.pb(0);
	sort(all(maxs));
	reverse(all(maxs));
	ans += 2*h[root] - maxs[0] - maxs[1];
	finish(ans);
}
