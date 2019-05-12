#include <bits/stdc++.h>
using namespace std;

class EllysPearls {
	int dp[51][51][15][15];
	int dp2[51][51];

  public:
	int getMin(int n, int m, vector<int> c) {
        for (int i = 0; i<)
		for (int i = 0; i < n; i++) {
			for (int cl = 0; cl < m; cl++) {
				for (int cr = 0; cr < m; cr++) {
					dp[i][i][cl][cr] = 1e9;
				}
			}
			dp[i][i][c[i]][c[i]] = 0;
		}
		for (int w = 1; w < n; w++) {
			for (int l = 0; l + w < n; l++) {
				int r = l + w;
				dp2[l][r] = 1e9;
				for (int cl = 0; cl < m; cl++) {
					for (int cr = 0; cr < m; cr++) {
						dp[l][r][cl][cr] = 1e9;
						if (cl == c[l]) {
							if (dp[l + 1][r][cl][cr] == 1e9)
								dp[l][r][cl][cr] = min(dp[l][r][cl][cr], dp2[l + 1][r]);
							dp[l][r][cl][cr] = min(dp[l][r][cl][cr], dp[l + 1][r][cl][cr]);
						}
						else {
							dp[l][r][cl][cr] = min(dp[l][r][cl][cr], 1 + dp[l + 1][r][cl][cr]);
						}
						if (cr == c[r]) {
							if (dp[l][r - 1][cl][cr] == 1e9)
								dp[l][r][cl][cr] = min(dp[l][r][cl][cr], dp2[l][r - 1]);
							dp[l][r][cl][cr] = min(dp[l][r][cl][cr], dp[l][r - 1][cl][cr]);
						}
						else {
							dp[l][r][cl][cr] = min(dp[l][r][cl][cr], 1 + dp[l][r - 1][cl][cr]);
						}
						dp2[l][r] = min(dp2[l][r], dp[l][r][cl][cr]);
					}
				}
			}
		}
        return dp2[0][n-1];
	}
};