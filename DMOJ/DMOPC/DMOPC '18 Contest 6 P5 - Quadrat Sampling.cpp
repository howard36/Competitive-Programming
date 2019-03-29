#include <bits/stdc++.h>
using namespace std;

int a[100005], b[100005], g[2003][2003], gg[4009][4009], sparse[12][4009], lg[4010], ans[100005];

int main() {
    // freopen("data.txt", "r", stdin);
	int n, m, k, q, t;
	scanf("%d %d %d %d %d", &n, &m, &k, &q, &t);
	for (int i = 0; i < k; i++) {
		scanf("%d %d", &a[i], &b[i]);
	}
	int r1, r2, c1, c2;
	for (int i = 0; i < q; i++) {
		scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
		r2++;
		c2++;
		g[r1][c1]++;
		g[r2][c1]--;
		g[r1][c2]--;
		g[r2][c2]++;
	}
	for (int i = 2; i <= 4009; i++) {
		lg[i] = lg[i / 2] + 1;
	}
	for (int i = 1; i <= 2000; i++) {
		for (int j = 1; j <= 2000; j++) {
			g[i][j] += g[i][j - 1] + g[i - 1][j] - g[i - 1][j - 1];
			gg[i - j + 2004][i + j] = g[i][j];
		}
	}
	for (int i = 0; i < 4009; i++) {
		for (int j = 0; j < 4009; j++) {
			sparse[0][j] = gg[i][j];
		}
		for (int kk = 1; kk <= 11; kk++) {
			int P = 1 << kk;
			int p = 1 << (kk - 1);
			for (int j = 0; j <= 4009 - P; j++) {
				sparse[kk][j] = max(sparse[kk - 1][j], sparse[kk - 1][j + p]);
			}
		}
		for (int j = 0; j < k; j++) {
			int x = a[j] - b[j] + 2004, y = a[j] + b[j];
			int x1 = max(x - t, 0), x2 = min(x + t, 4008);
			int y1 = max(y - t, 0), y2 = min(y + t, 4008);
			if (x1 <= i && i <= x2) {
				int kk = lg[y2 - y1 + 1];
				ans[j] = max(ans[j], max(sparse[kk][y1], sparse[kk][y2 - (1 << kk) + 1]));
			}
		}
	}

	int sum = 0;
	for (int i = 0; i < k; i++) {
        // printf("ans[%d] = %d\n", i, ans[i]);
		sum += ans[i];
	}
	printf("%d", sum);
}