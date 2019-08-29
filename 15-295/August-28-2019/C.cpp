#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>

int a[10];
vvi ans;

int main() {
	int n, m = 100, M = -1;
	double r;
	scanf("%d %lf", &n, &r);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		m = min(m, a[i]);
		M = max(M, a[i]);
	}
	while (r >= M) {
		ans.push_back(vi(1, M));
		r -= M;
	}
	while (r >= 0.01) {
		// printf("r = %.2lf\n", r);
		int cnt = int(m / r + 1 - 1e-6);
        // printf("cnt = %d\n", cnt);
		ans.push_back(vi(cnt, m));
		r -= 1.0 * m / cnt;
	}

	printf("%d\n", (int)ans.size());
	for (int i = 0; i < ans.size(); i++) {
        printf("%d ", (int)ans[i].size());
		for (int j : ans[i])
			printf("%d ", j);
		printf("\n");
	}
}