#include <bits/stdc++.h>
using namespace std;

int dp[8][256][256], orig[512][512], ans[512][512], psa[513][513], temp[2][2][2][2];

int sum(int k, int x, int y) {
	return psa[(x + 1) << k][(y + 1) << k] - psa[(x + 1) << k][y << k] - psa[x << k][(y + 1) << k] + psa[x << k][y << k];
}

int main() {
    freopen("data.txt", "r", stdin);
	int n;
	scanf("%d", &n);
    char c;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf(" %c", &c);
            orig[i][j] = c - '0';
            ans[i][j] = orig[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			psa[i + 1][j + 1] = orig[i][j] + psa[i + 1][j] + psa[i][j + 1] - psa[i][j];
            // printf("psa[%d][%d] = %d\n", i+1, j+1, psa[i+1][j+1]);
		}
	}
	for (int i = 0; i < n / 2; i++) {
		for (int j = 0; j < n / 2; j++) {
			int s = sum(1, i, j);
			if (s == 0) {
				dp[0][i][j] = 1;
				ans[2 * i][2 * j] = 1;
			}
			else if (s == 4) {
				dp[0][i][j] = 1;
				ans[2 * i][2 * j] = 0;
			}
            // printf("sum(1, %d, %d) = %d\n", i, j, s);
            // printf("dp[0][%d][%d] = %d\n", i, j, dp[0][i][j]);
		}
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			temp[i][j][i][j] = 1e9;
		}
	}
	for (int k = 1; (1 << (k + 1)) <= n; k++) {
		for (int x = 0; x < (n >> (k + 1)); x++) {
			for (int y = 0; y < (n >> (k + 1)); y++) {
				int minTemp = 1e9;
				for (int i1 = 0; i1 < 2; i1++) {
					for (int j1 = 0; j1 < 2; j1++) {
						for (int i2 = 0; i2 < 2; i2++) {
							for (int j2 = 0; j2 < 2; j2++) {
								if (i1 == i2 && j1 == j2)
									continue;
								temp[i1][j1][i2][j2] = sum(k, 2 * x + i1, 2 * y + j1) + (1 << (2 * k)) - sum(k, 2 * x + i2, 2 * y + j2);
								for (int i3 = 0; i3 < 2; i3++) {
									for (int j3 = 0; j3 < 2; j3++) {
										if (i3 == i1 && j3 == j1 || i3 == i2 && j3 == j2)
											continue;
										temp[i1][j1][i2][j2] += dp[k - 1][2 * x + i3][2 * y + j3];
									}
								}
                                // printf("temp[%d][%d][%d][%d] = %d\n", i1, j1, i2, j2, temp[i1][j1][i2][j2]);
								minTemp = min(minTemp, temp[i1][j1][i2][j2]);
							}
						}
					}
				}
                
                bool filled = false;
				for (int i1 = 0; i1 < 2; i1++) {
					for (int j1 = 0; j1 < 2; j1++) {
						for (int i2 = 0; i2 < 2; i2++) {
							for (int j2 = 0; j2 < 2; j2++) {
								if (i1 == i2 && j1 == j2 || filled)
									continue;
								if (temp[i1][j1][i2][j2] == minTemp) {
                                    filled = true;
									dp[k][x][y] = minTemp;
									for (int xx = ((2 * x + i1) << k); xx < ((2 * x + i1 + 1) << k); xx++) {
										for (int yy = ((2 * y + j1) << k); yy < ((2 * y + j1 + 1) << k); yy++) {
											ans[xx][yy] = 0;
										}
									}
									for (int xx = ((2 * x + i2) << k); xx < ((2 * x + i2 + 1) << k); xx++) {
										for (int yy = ((2 * y + j2) << k); yy < ((2 * y + j2 + 1) << k); yy++) {
											ans[xx][yy] = 1;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}

    int lastLevel = 0;
	for (int k = 1; (1 << (k + 1)) <= n; k++) {
        lastLevel = k;
    }

    printf("%d\n", dp[lastLevel][0][0]);
    for (int i = 0; i<n; i++){
        for (int j = 0; j<n; j++){
            printf("%d", ans[i][j]);
        }
        printf("\n");
    }
}