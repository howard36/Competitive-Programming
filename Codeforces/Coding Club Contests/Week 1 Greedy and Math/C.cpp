#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll t[100005];

int main() {
	ll s, e, T;
	int n;
	scanf("%lld %lld %lld %d", &s, &e, &T, &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &t[i]);
	}
	sort(t, t + n);
	t[n] = 1e18;
	ll best = 1e18;
	ll bestTime = -1;
	for (int cur = 0; cur <= n; cur++) {
		ll start = min(e-T, t[cur] - 1);
		ll end = s + T * cur;
		ll wait = end - start;
		if (end > e - T)
			break;
		if (wait <= 0) {
			printf("%lld", start);
			return 0;
		}
		if (wait < best) {
			best = wait;
			bestTime = start;
		}
	}
	printf("%lld", bestTime);
}