#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define FAST ios::sync_with_stdio(0); cin.tie(0);

struct Line {
	mutable ld k, m, p;
	ld eval (ld x) { return k*x+m; }
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ld x) const { return p < x; }
};

struct LC : multiset<Line,less<>> {
	const ld inf = 1/.0;
	ld div(ld a, ld b) { return a/b; }
	ld bet(const Line& x, const Line& y) {
		if (x.k == y.k) return x.m >= y.m ? inf : -inf;
		return div(y.m-x.m, x.k-y.k);
	}
	bool isect(iterator x, iterator y) {
		if (y == end()) { x->p = inf; return 0; }
		x->p = bet(*x,*y); return x->p >= y->p;
	}
	void add(ld k, ld m) {
		auto z = insert({k,m,0}), y = z++, x = y;
		while (isect(y,z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y=erase(y));
		while ((y=x) != begin() && (--x)->p >= y->p) isect(x, erase(y));
	}
	ld query(ld x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k*x+l.m;
	}
};

ld s[50004], b[50004];

int main() { FAST
	LC lc;
	lc.add(0,0);

	int n, q;
	cin >> n >> q;
	while (q--) {
		ll type, t, c, sp;
		cin >> type >> t;
		if (type == 1) {
			cin >> c >> sp;
			ld pos = s[c] * t + b[c];
			s[c] = sp;
			b[c] = pos - t * s[c];
			lc.add(s[c], b[c]);
		}
		else {
			cout << (ll)(lc.query(t) + 0.5) << endl;
		}
	}
}

