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
typedef pair<ll, pi> ppi;

int a[300005], b[300005], start[300005], ans[300005];
pi p[300005];
ll n, l, s;
set<int> to[300005];

void solve() {
	priority_queue<ppi, vector<ppi>, greater<ppi> > pq;
	for (int i = 0; i<l; i++)
		pq.push(ppi(i, p[i]));
	while (!pq.empty()) {
		ppi pp = pq.top();
		pq.pop();
		ll t = pp.f;
		if (t >= s)
			break;
		int c = pp.s.f, d = pp.s.s;
		if (a[c] == 0 && a[d] == 1) {
			a[c] = 1;
			for (int i : to[c]) {
				if (a[p[i].f] == 0) {
					ll t2 = t + (i-(t%l)+l) % l;
					pq.push(ppi(t2, p[i]));
				}
			}
		}
	}
}

int main() { FAST
	cin >> n >> l >> s;
	for (int i = 0; i<l; i++) {
		int ta, tb;
		cin >> ta >> tb;
		p[i] = pi(ta,tb);
		to[tb].insert(i);
	}
	for (int i = 1; i<=n; i++)
		cin >> start[i];
	for (int i = 0; i<8; i++) {
		for (int j = 1; j<=n; j++)
			a[j] = (start[j]>>i)&1;
		solve();
		for (int j = 1; j<=n; j++)
			ans[j] += a[j]<<i;
	}
	for (int i = 1; i<=n; i++)
		cout << ans[i] << " ";
	cout << "\n";
}
