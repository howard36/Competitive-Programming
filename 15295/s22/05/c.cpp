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
int ans[100005], x[100005];

void dfs(int v, int p, int f1, int f2) {
	if (x[v] ^ f1 == 1) {
		ans[v] = 1;
		f1 ^= 1;
	}
	for (int u : adj[v]) {
		if (u == p) continue;
		dfs(u, v, f2, f1);
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
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
	}
	for (int i = 1; i <= n; i++) {
		int tmp;
		cin >> tmp;
		x[i] ^= tmp;
	}
	dfs(1, -1, 0, 0);
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		if (ans[i])
			sum++;
	}
	cout << sum << endl;
	for (int i = 1; i <= n; i++) {
		if (ans[i])
			cout << i << endl;
	}
}
