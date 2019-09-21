#include <bits/stdc++.h>
using namespace std;

int d[102], h[102];

int main() {
	int t, n, x;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &x);
		int m = 0, M = 0;
		for (int i = 0; i<n; i++) {
			scanf("%d %d", &d[i], &h[i]);
			m = max(m, d[i]-h[i]);
			M = max(M, d[i]);
		}
		if (x <= M)
			printf("1\n");
		else if (m <= 0)
			printf("-1\n");
		else
			printf("%d\n", 1+ (x-M + m - 1)/m);
	}
}
