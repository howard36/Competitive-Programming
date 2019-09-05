#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll a[100005], b[100005];
ll n, s;

ll price(ll k) {
	for (int i = 1; i<=n; i++)
		b[i] = a[i] + i*k;
	sort(b+1, b+n+1);
	ll sum = 0;
	for (int i = 1; i<=k; i++)
		sum += b[i];
	return sum;
}

int main() {
	scanf("%lld %lld", &n, &s);
	for (int i = 1; i<=n; i++)
		scanf("%lld", &a[i]);
	int lo = 0, hi = n;
	while (lo < hi) {
		int mid = (lo+hi+1)/2;
		if (price(mid) <= s)
			lo = mid;
		else
			hi = mid - 1;
	}
	printf("%d %lld\n", lo, price(lo));
}
