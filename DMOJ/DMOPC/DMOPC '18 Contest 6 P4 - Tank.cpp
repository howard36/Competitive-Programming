#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll u[200005], v[200005], a[200005], b[200005], psaa[200005], psab[200005], ans[200005];

int main() {
	int n, p, m;
	scanf("%d %d %d", &n, &p, &m);
	for (int i = 0; i < n; i++) {
		scanf("%lld %lld", &u[i], &v[i]);
	}
	for (int i = 1; i <= p; i++) {
		scanf("%lld", &a[i]);
	}
	for (int i = 1; i <= m; i++) {
		scanf("%lld", &b[i]);
	}
	sort(a + 1, a + p + 1);
	sort(b + 1, b + m + 1);
	for (int i = 1; i <= p; i++) {
		psaa[i] = psaa[i - 1] + a[i];
	}
	for (int i = 1; i <= m; i++) {
		psab[i] = psab[i - 1] + b[i];
	}
	ll best = 1e18;
	for (int i = 0; i < n; i++) {
		int idx = upper_bound(a, a + p + 1, u[i]) - a - 1;
        // printf("idx = %d\n", idx);
		ans[i] = psaa[p] - psaa[idx] - (p - idx) * u[i];
        // printf("ans[%d] = %lld\n", i, ans[i]);
		idx = upper_bound(b, b + m + 1, v[i]) - b - 1;
		ans[i] += psab[m] - psab[idx] - (m - idx) * v[i];
		best = min(best, ans[i]);
        // printf("ans[%d] = %lld\n", i, ans[i]);
	}
    // printf("best = %lld\n", best);
	for (int i = 0; i < n; i++) {
		if (ans[i] == best) {
			printf("%d", i + 1);
			return 0;
		}
	}
}