#include <bits/stdc++.h>
using namespace std;
#define ll long long

int a[100005], b[100005], psa[100005], bit[200005];
int n;

void update(int i) {
	for (; i < 200005; i += (i & -i))
		bit[i]++;
}

int query(int i) {
	int ans = 0;
	for (; i > 0; i -= (i & -i))
		ans += bit[i];
	return ans;
}

bool test(int m) {
	memset(bit, 0, sizeof bit);
	update(n + 1);
	psa[0] = 0;
	ll cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i-1] >= m)
			b[i] = 1;
		else
			b[i] = -1;
		psa[i] = psa[i - 1] + b[i];
		cnt += query(psa[i] + n + 1);
		update(psa[i] + n + 1);
	}
	return cnt >= (1LL * n * (n + 1) / 2 + 1) / 2;
}

int main() {
	scanf("%d", &n);
	int lo = 1, hi = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		hi = max(hi, a[i]);
	}
	while (lo < hi) {
		int mid = (lo + hi + 1) / 2;
		if (test(mid))
			lo = mid;
		else
			hi = mid - 1;
	}
	printf("%d", lo);
}