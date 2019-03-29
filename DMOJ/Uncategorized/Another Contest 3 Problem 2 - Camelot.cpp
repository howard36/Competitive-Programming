#include <bits/stdc++.h>
using namespace std;
#define ll long long

int x[1000006], y[1000006], a[1000006], b[1000006];
int n;

ll query(ll X, ll Y) {
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ans += abs(X - x[i]);
		ans += abs(Y - y[i]);
	}
	return ans / 2;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a[i], &b[i]);
		x[i] = a[i] + b[i];
		y[i] = a[i] - b[i];
	}
	sort(x, x + n);
	sort(y, y + n);
	int X = x[n / 2], Y = y[n / 2];
	if ((X + Y) % 2 == 0) {
		printf("%lld\n", query(X, Y));
	}
	else {
		ll best = 1e18;
		best = min(best, query(X + 1, Y));
		best = min(best, query(X - 1, Y));
		best = min(best, query(X, Y + 1));
		best = min(best, query(X, Y - 1));
        printf("%lld\n", best);
	}
}