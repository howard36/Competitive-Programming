#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll p[1000006];

ll gcd(ll a, ll b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

ll query1(ll i) {
	cout << "? " << i << endl;
	fflush(stdout);
	ll ans;
	cin >> ans;
	return ans;
}

ll query2(ll x) {
	cout << "> " << x << endl;
	fflush(stdout);
	ll ans;
	cin >> ans;
	return ans;
}

int main() {
	ll n;
	scanf("%lld", &n);
	ll lo = 0, hi = 1e9;
	ll queries = 0;
	while (lo < hi) {
		ll mid = (lo + hi) / 2;
		if (query2(mid)) {
			lo = mid + 1;
		}
		else {
			hi = mid;
		}
		queries++;
	}
	for (ll i = 0; i < n; i++) {
		p[i] = i + 1;
	}
	srand(100);
	random_shuffle(p, p + n);
	ll d = lo - query1(p[0]);
	for (ll i = 1; i < min(n, 59 - queries); i++) {
		ll diff = lo - query1(p[i]);
		d = gcd(d, diff);
	}
	cout << "! " << lo - (n - 1) * d << " " << d << endl;
	fflush(stdout);
}