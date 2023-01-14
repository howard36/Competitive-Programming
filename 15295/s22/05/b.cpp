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

vector<int> adj[100005];
int depth[100005];

void dfs(int v, int p, int d) {
	depth[v] = d;
	for (int u : adj[v]) {
		if (u == p) continue;
		dfs(u, v, d+1);
	}
}

int main() { FAST
	int n;
	cin >> n;
	for (int i = 0; i < n-1; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	dfs(1, -1, 1);
	ll x = 0, y = 0, z = 0;
	for (int i = 1; i <= n; i++) {
		if (depth[i] == 0)
			z++;
		else if (depth[i] % 2 == 0)
			x++;
		else
			y++;
	}
	while (z--) {
		if (x < y) x++;
		else y++;
	}
	cout << x*y-(n-1) << endl;
}
