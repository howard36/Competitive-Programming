#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<ll, int>

pi a[300005];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i].first);
		a[i].second = i + 1;
	}
	sort(a, a + n);
	int k;
	scanf("%d", &k);
	ll sum = 0, score = 0;
	for (int i = 0; i < k; i++) {
		score += i * a[i].first - sum;
		sum += a[i].first;
	}
	ll best = score;
	int besti = 0;
	for (int i = 0; i + k < n; i++) {
		sum -= a[i].first;
		score -= sum - (k - 1) * a[i].first;
		score += (k - 1) * a[i + k].first - sum;
		sum += a[i + k].first;
		if (score < best) {
			best = score;
			besti = i + 1;
		}
	}
	for (int i = 0; i < k; i++) {
		printf("%d ", a[i + besti].second);
	}
}