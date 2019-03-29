#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ll n, k;
	scanf("%lld %lld", &n, &k);
    if (k > 1e6){
		printf("-1");
		return 0;
    }
	ll s = k * (k + 1) / 2;
	if (s > n) {
		printf("-1");
		return 0;
	}
	ll maxD = 1;
	for (ll d = 1; d * d <= n; d++) {
		if (n % d == 0) {
			if (d * s <= n)
				maxD = max(maxD, d);
			if (n / d <= n / s)
				maxD = max(maxD, n / d);
		}
	}
	for (ll i = 1; i < k; i++) {
		printf("%lld ", maxD * i);
	}
	printf("%lld", n - maxD * k * (k - 1) / 2);
}