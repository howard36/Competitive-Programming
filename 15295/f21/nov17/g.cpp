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
typedef vector<pair<int,int>> vpi;
typedef pair<ld,ld> pd;
typedef complex<ld> cd;

vpi adj[200005], tmp;
ll inc[200005], decc[200005];
int w[200005];
int par[200005];

void dfs(int i) {
	inc[i] = decc[i] = 1;
	for (auto p : adj[i]) {
		if (p.f != par[i]) {
			par[p.f] = i;
			w[p.f] = p.s;
			dfs(p.f);
			if (p.s < w[i])
				inc[i] += inc[p.f];
			if (p.s > w[i])
				decc[i] += decc[p.f];
		}
	}
	dbg(i _ inc[i] _ decc[i]);
}

int main() { FAST
	int n;
	cin >> n;
	for (int i = 0; i<n-1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].pb(mp(b,c));
		adj[b].pb(mp(a,c));
	}
	dfs(1);
	ll ans = 0;
	for (int i = 1; i<=n; i++) {
		if (i != 1)
			ans += inc[i] + decc[i];
		tmp.clear();
		for (auto p : adj[i]) {
			if (p.f != par[i])
				tmp.pb(mp(p.s, p.f));
		}
		sort(all(tmp));
		ll sinc = 0, lastw = -1, tdecc = 0, tinc = 0;
		for (auto p : tmp) {
			if (p.f > lastw) {
				ans += sinc * tdecc;
				dbg(i _ p.s _ sinc*tdecc _ ans)
				sinc += tinc;
				tinc = inc[p.s];
				tdecc = decc[p.s];
				lastw = p.f;
			} else {
				tinc += inc[p.s];
				tdecc += decc[p.s];
			}
			dbg(sinc _ tinc _ tdecc)
		}
		ans += sinc * tdecc;
		dbg(i _ sinc _ tdecc _ ans)
	}
	cout << ans << "\n";
}
