#include <bits/stdc++.h>
using namespace std;
#define pi pair<int, int>
#define ppi pair<int, pi>

ppi dp[3003][3003];

int main() {
	string s, t;
	cin >> s >> t;
	int n = s.length(), m = t.length();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (s[i - 1] == t[j - 1]) {
				dp[i][j] = ppi(dp[i - 1][j - 1].first + 1, pi(i - 1, j - 1));
			}
			else {
				if (dp[i - 1][j].first > dp[i][j - 1].first) {
					dp[i][j] = ppi(dp[i - 1][j].first, pi(i - 1, j));
				}
				else {
					dp[i][j] = ppi(dp[i][j - 1].first, pi(i, j - 1));
				}
			}
		}
	}
	string ans;
	for (pi state = pi(n, m); state != pi(0, 0); state = dp[state.first][state.second].second) {
		int i = state.first, j = state.second;
		if (dp[i][j].second == pi(i - 1, j - 1)) {
			ans = s[i - 1] + ans;
		}
	}
	cout << ans;
}