#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n, m, p[100005], c[100005];

bool enough(ll t) {
	ll sum = 0;
	for (int i = 0; i<n; i++) {
		sum += max(p[i]*t-c[i], 0LL);
		if (sum >= m)
			return true;
	}
	return false;
}

int main() {
	scanf("%lld %lld", &n, &m);
	for (int i = 0; i<n; i++)
		scanf("%lld %lld", &p[i], &c[i]);
	ll lo = 1, hi = 2e9;
	while (lo < hi) {
		ll mid = (lo + hi)/2;
		//printf("mid = %lld, hi = %lld\n", mid, hi);
		if (enough(mid))
			hi = mid;
		else
			lo = mid + 1;
	}
	printf("%lld\n", lo);
}
