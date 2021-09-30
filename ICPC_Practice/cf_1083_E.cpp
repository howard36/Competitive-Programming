#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define ll long long
#define pi pair<ll, ll>
#define ppi pair<pi, ll>
#define f first
#define s second
#define FAST ios::sync_with_stdio(0); cin.tie(0);

struct Line {
	mutable ll k, m, p;
	ll eval (ll x) { return k*x+m; }
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
};

struct LC : multiset<Line,less<>> {
	const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { return a/b - ((a^b) < 0 && a%b); }
	ll bet(const Line& x, const Line& y) {
		if (x.k == y.k) return x.m >= y.m ? inf : -inf;
		return div(y.m-x.m, x.k-y.k);
	}
	bool isect(iterator x, iterator y) {
		if (y == end()) { x->p = inf; return 0; }
		x->p = bet(*x,*y); return x->p >= y->p;
	}
	void add(ll k, ll m) {
		auto z = insert({k,m,0}), y = z++, x = y;
		while (isect(y,z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y=erase(y));
		while ((y=x) != begin() && (--x)->p >= y->p) isect(x, erase(y));
	}
	ll query(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k*x+l.m;
	}
};

ppi p[1000006];
ll a[1000006], dp[1000006];

int main() { FAST
	int n;
	cin >> n;
	for (int i = 0; i<n; i++)
		cin >> p[i].f.f >> p[i].f.s >> p[i].s;
	sort(p, p+n);

	LC lc;
	lc.add(0, 0);
	ll ans = 0;
	for (int i = 0; i<n; i++) {
		dp[i] = p[i].f.f * p[i].f.s - p[i].s + lc.query(p[i].f.s);
		lc.add(-p[i].f.f, dp[i]);
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
}

