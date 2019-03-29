#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int prime[1000006];

int main() {
	ll n, b;
	scanf("%lld %lld", &n, &b);
	for (ll i = 2; i < 1000006; i++) {
		prime[i] = 1;
	}
	for (ll i = 2; i < 1000006; i++) {
		if (prime[i]) {
			for (ll j = i * i; j < 1000006; j += i)
				prime[j] = 0;
		}
	}
	// printf("Hi\n");
	ll ans = 1e18;
	for (ll i = 2; i < 1000006; i++) {
		if (prime[i] && b % i == 0) {
			ll vpb = 0;
			while (b % i == 0) {
				b /= i;
				vpb++;
			}
			ll vpn = 0, tempn = n / i;
			while (tempn > 0) {
				vpn += tempn;
				tempn /= i;
			}
			ans = min(ans, vpn / vpb);
		}
	}
	if (b > 1) {
		ll vpn = 0, tempn = n / b;
		while (tempn > 0) {
			vpn += tempn;
			tempn /= n;
		}
		ans = min(ans, vpn);
	}
	printf("%lld", ans);
}