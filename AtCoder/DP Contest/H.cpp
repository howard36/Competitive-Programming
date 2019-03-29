#include <bits/stdc++.h>
using namespace std;

int dp[1003][1003];

int main() {
	int h, w;
	scanf("%d %d", &h, &w);
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			char c;
			scanf(" %c", &c);
			if (c == '.') {
				dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000007;
                if (i*j == 1)
                    dp[i][j] = 1;
			}
		}
	}
    printf("%d", dp[h][w]);
}