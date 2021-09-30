#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FAST ios::sync_with_stdio(0); cin.tie(0);
#define pl pair<ll,ll>
#define ppl pair<pl,pl>
#define f first
#define s second

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

int main() { FAST
	ll n, c, d, cases = 1;
	while (true) {
		cin >> n >> c >> d;
		if (n == 0)
			break;
		LC lc;
		lc.add(0, c);

		vector<ppl> v;
		ll day, r, p, g;
		for (int i = 0; i<n; i++) {
			cin >> day >> p >> r >> g;
			v.push_back(ppl(pl(day, r), pl(p, g)));
		}
		sort(v.begin(), v.end());
		for (int i = 0; i<n; i++) {
			day = v[i].f.f, r = v[i].f.s, p = v[i].s.f, g = v[i].s.s;
			ll M = lc.query(day);
			if (M >= p) {
				//cout << "Adding line through (" << day << ", " << M-p+r << ") with slope " << g << endl;
				lc.add(g, M-p+r-day*g-g);
			}
		}
		cout << "Case " << cases++ << ": " << lc.query(d+1) << endl;
	}
}

