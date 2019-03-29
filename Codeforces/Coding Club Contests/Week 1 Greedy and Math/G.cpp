#include <bits/stdc++.h>
using namespace std;

int a[102], psa[102];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a + 1, a + n + 1, greater<int>());
	for (int i = 1; i <= n; i++) {
		psa[i] = psa[i - 1] + a[i];
	}
	for (int i = 1; i <= n; i++) {
		if (2 * psa[i] > psa[n]) {
			printf("%d", i);
			return 0;
		}
	}
}