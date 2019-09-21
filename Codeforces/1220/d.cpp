#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int, int>

ll a[200005], b[200005], c[70];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
		ll t = a[i];
		while (t % 2 == 0) {
			t /= 2;
			b[i]++;
		}
		c[b[i]]++;
	}
	int best = 0;
	for (int i = 0; i<70; i++) {
		if (c[i] > c[best])
			best = i;
	}
	printf("%d\n", n-c[best]);
	for (int i = 0; i<n; i++) {
		if (b[i] != best)
			printf("%lld ", a[i]);
	}
}
