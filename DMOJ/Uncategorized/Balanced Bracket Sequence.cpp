#include <bits/stdc++.h>
using namespace std;

int dp[302][302];

int main() {
	string s;
	cin >> s;
	int n = s.length();
	for (int i = 0; i < n; i++) {
		dp[i][i] = 1;
	}
	for (int w = 1; w < n; w++) {
		for (int l = 0; l + w < n; l++) {
			dp[l][l + w] = 1e9;
			if ((s[l] == '(' && s[l + w] == ')') || (s[l] == '[' && s[l + w] == ']'))
				dp[l][l + w] = dp[l + 1][l + w - 1];
			for (int i = l; i < l + w; i++)
				dp[l][l + w] = min(dp[l][l + w], dp[l][i] + dp[i + 1][l + w]);
		}
	}
	printf("%d", dp[0][n - 1]);
}