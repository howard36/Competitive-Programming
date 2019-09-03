#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pl pair<ll, ll>

ll f[100005];
ll n, a, b;

ll psa(ll f1, ll f2, ll x) {
	if (x <= f1)
		return x*(x-1)/2;
	else if (x <= f2)
		return f1*(f1-1)/2 + (x-f1)*f1;
	else {
		ll m = max(0LL, f1 + f2 - x);
		return f1*f2 - m*(m+1)/2;
	}
}

pl prob(ll x, ll y) {
	return make_pair(psa(f[x], f[y], b) - psa(f[x], f[y], a-1), f[x]*f[y]);
}

ll diff(pl x, pl y) {
	return x.first * y.second - y.first * x.second;
}

ll gcd(ll x, ll y) {
	if (y == 0) return x;
	return gcd(y, x%y);
}

int main() {
	scanf("%lld %lld %lld", &n, &a, &b);
	for (int i = 0; i<n; i++)
		scanf("%lld", &f[i]);
	sort(f, f+n);
	int L = 0, R = n-1, r = n-1;
	for (int l = 0; l < n-1; l++) {
//		if (r == l)
//			r++; // annoying edge case
//		while (r-1 > l && diff(prob(l, r-1), prob(l, r)) >= 0)
//			r--;
		if (diff(prob(l, l+1), prob(L, R)) > 0) {
			L = l;
			R = l+1;
		}
	}
	pl p = prob(L, R);
	ll num = p.first, den = p.second;
	ll d = gcd(num, den);
	printf("%lld/%lld\n", num/d, den/d);
}
