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
typedef pair<ll,ll> pi;
typedef pair<int,pi> ppi;
typedef pair<ld,ld> pd;
typedef complex<ld> cd;

vector<pi> adj[200005];
ll cost[100005];
vector<pi> rows[100005];
priority_queue<ppi, vector<ppi>, greater<ppi>> pq;
ll dist[200005];
int pos[200005];

int main() { FAST
	int t;
	cin >> t;
	while (t--) {
		int n, m, k;
		cin >> n >> m >> k;
		for (int i = 0; i<=2*k+1; i++)
			adj[i].clear();
		for (int i = 1; i<=n; i++)
			rows[i].clear();
		while (!pq.empty())
			pq.pop();

		for (int i = 1; i<=n; i++)
			cin >> cost[i];
		for (int i = 1; i<=k; i++) {
			int a, b, c, d, h;
			cin >> a >> b >> c >> d >> h;
			pos[2*i] = a;
			pos[2*i+1] = c;
			rows[a].pb(mp(b,2*i));
			rows[c].pb(mp(d,2*i+1));
			adj[2*i].pb(mp(2*i+1, -h));
		}
		rows[1].pb(mp(1,0));
		rows[n].pb(mp(m,1));
		pos[0] = 1;
		pos[1] = n;
		for (int i = 1; i<=n; i++) {
			sort(all(rows[i]));
			for (int j = 0; j<sz(rows[i])-1; j++) {
				pi p = rows[i][j], q = rows[i][j+1];
				adj[p.s].pb(mp(q.s, cost[i]*(q.f-p.f)));
				adj[q.s].pb(mp(p.s, cost[i]*(q.f-p.f)));
			}
		}

		for (int i = 0; i<=2*k+1; i++) {
			dist[i] = 1e18;
		}
		dist[0] = 0;
		pq.push(mp(1, mp(0, 0)));
		while (!pq.empty()) {
			ppi p = pq.top(); pq.pop();
			if (p.s.f > dist[p.s.s])
				continue;
			if (p.s.s == 1)
				break;
			for (pi q : adj[p.s.s]) {
				if (p.s.f + q.s < dist[q.f]) {
					dist[q.f] = p.s.f + q.s;
					pq.push(mp(pos[q.f], mp(dist[q.f], q.f)));
				}
			}
		}
		if (dist[1] == 1e18)
			cout << "NO ESCAPE\n";
		else
			cout << dist[1] << "\n";
	}
}
