#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int, int>

ll c[100005];
string s[100005], t[100005];
ll dp[100005][2];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i<=n; i++)
		scanf("%lld", &c[i]);
	for (int i = 1; i<=n; i++) {
		cin >> s[i];
		t[i] = s[i];
		reverse(t[i].begin(), t[i].end());
		dp[i][0] = dp[i][1] = 1e18;
	}
	s[0] = "a";
	t[0] = "a";
	for (int i = 1; i<=n; i++) {
		if (s[i] >= s[i-1])
			dp[i][0] = min(dp[i][0], dp[i-1][0]);
		if (s[i] >= t[i-1])
			dp[i][0] = min(dp[i][0], dp[i-1][1]);
		if (t[i] >= s[i-1])
			dp[i][1] = min(dp[i][1], dp[i-1][0] + c[i]);
		if (t[i] >= t[i-1])
			dp[i][1] = min(dp[i][1], dp[i-1][1] + c[i]);
	}
	ll ans = min(dp[n][0], dp[n][1]);
	if (ans == 1e18)
		printf("-1\n");
	else
		printf("%lld\n", ans);
}
