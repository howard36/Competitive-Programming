#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int, int>

int dp[1003][1003];

int main() {
	string s;
	cin >> s;
	int n = s.length();
	for (int i = 0; i<n; i++) {
		dp[i][i] = 1;
		dp[i][i+1] = 1;
	}
	for (int l = 2; l<=n; l++) {
		for (int i = 0; i+l <= n; i++) {
			int r = i + l - 1;
			if (s[i] == s[r])
				dp[i][i+l] |= dp[i+1][r];
			if (s[i] == s[i+1])
				dp[i][i+l] |= dp[i+2][i+l];
			if (s[r-1] == s[r])
				dp[i][i+l] |= dp[i][r-1];
		}
	}
	if (dp[0][n])
		printf("POSSIBLE\n");
	else
		printf("IMPOSSIBLE\n");
}
