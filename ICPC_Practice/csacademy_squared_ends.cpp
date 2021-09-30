#include <bits/stdc++.h>
using namespace std;
#define ll long long
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

ll a[10004], dp[10004][102];

int main() { FAST
	int n, K;
	cin >> n >> K;
	for (int i = 0; i<n; i++) {
		cin >> a[i];
		for (int k = 0; k<=K; k++)
			dp[i][k] = 1e18;
	}

	for (int k = 1; k<=K; k++) {
		LC lc;
		lc.add(2*a[k-1], -a[k-1]*a[k-1]);
		for (int i = k; i<n; i++) {
			dp[i][k] = a[i]*a[i] - lc.query(a[i]);
			lc.add(2*a[i+1], -(a[i+1]*a[i+1] + dp[i][k-1]));
		}
	}
	cout << dp[n-1][K] << endl;
}

