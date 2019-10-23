#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007LL

vector<ll> primes;

ll fastexp(ll a, ll b) {
	ll ans = 1;
	while (b) {
		if (b%2 == 1) 
			ans = (ans*a)%mod;
		b /= 2;
		a = (a*a)%mod;
	}
	return ans;
}

int main() {
	ll x, n;
	scanf("%lld %lld", &x, &n);
	for (ll d = 2; d*d <= x; d++) {
		if (x%d == 0) {
			primes.push_back(d);
			while (x%d == 0)
				x /= d;
		}
	}
	if (x > 1)
		primes.push_back(x);
	ll ans = 1;
	for (ll p : primes) {
		ll vp = 0, nn = n;
		while (nn) {
			nn /= p;
			vp += nn;
		}
		ans = (ans * fastexp(p, vp)) % mod;
	}
	printf("%lld", ans);
}
