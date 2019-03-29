#include <bits/stdc++.h>
using namespace std;

int a[502];

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int ans = 0;
	for (int i = 1; i < n; i++) {
		ans += max(0, k - a[i] - a[i - 1]);
		a[i] += max(0, k - a[i] - a[i - 1]);
	}
	printf("%d\n", ans);
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
}