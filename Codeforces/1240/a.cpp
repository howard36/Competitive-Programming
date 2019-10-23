#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll p[200005];
int n, a, b;
ll x, y, K;
ll psa[200005];

int gcd(int c, int d) {
	if (d == 0) return c;
	return gcd(d, c%d);
}

bool works(int k) {
	ll lcm = 1LL * a * b / gcd(a, b);
	int llcm = k / lcm;
	int aa = k / a - llcm;
	int bb = k / b - llcm;
	ll tot1 = (x+y)*psa[llcm] + x*(psa[aa + llcm]-psa[llcm]) + y*(psa[bb+aa+llcm]-psa[aa+llcm]);
	ll tot2 = (x+y)*psa[llcm] + y*(psa[bb + llcm]-psa[llcm]) + x*(psa[bb+aa+llcm]-psa[bb+llcm]);
	return tot1 >= K || tot2 >= K;
}

int main() {
	int q;
	scanf("%d", &q);
	while (q--) {
		scanf("%d", &n);
		for (int i = 0; i<n; i++) {
			scanf("%lld", &p[i]);
			p[i] /= 100;
		}
		sort(p, p+n);
		reverse(p, p+n);
		psa[0] = 0;
		for (int i = 1; i<=n; i++)
			psa[i] = psa[i-1] + p[i-1];
		scanf("%lld %d %lld %d %lld", &x, &a, &y, &b, &K);
		int lo = 1, hi = n+1;
		while (lo < hi) {
			int mid = (lo+hi)/2;
			if (works(mid))
				hi = mid;
			else
				lo = mid + 1;
		}
		if (lo == n+1)
			lo = -1;
		printf("%d\n", lo);
	}
}
