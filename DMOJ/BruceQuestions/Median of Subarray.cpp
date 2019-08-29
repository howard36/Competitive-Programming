#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<ll, ll>

ll a[100005], psa[100005], bit[300005];

void update(int i) {
	for (; i < 300005; i += (i & -i)) {
		bit[i]++;
	}
}

ll query(int i) {
	ll ans = 0;
	for (; i > 0; i -= (i & -i)) {
		ans += bit[i];
	}
	return ans;
}

int main() {
	int n, l, A;
	scanf("%d %d", &n, &l);
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &A);
		a[i] = (ll)(A >= l);
		psa[i] = psa[i - 1] + a[i - 1];
		ans += query(2 * psa[i] - i + n + 1);
		// printf("q = %lld\n", query(2*psa[i] - i + n + 1));
		update(2 * psa[i] - i + n + 1);
	}
	ans += query(2 * (psa[n] + a[n]));
	printf("%lld", ans);
}