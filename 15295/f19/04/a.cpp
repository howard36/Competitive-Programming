#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int, int>

set<int> dp[300005];
int t[300005];

void combine(int a, int b) {
	for (int i : dp[b]) {
		if (a-b == 2)
			dp[a].insert(i+1);
		else
			dp[a].insert(i);
	}
	while (dp[a].size() > 2)
		dp[a].erase(++dp[a].begin());
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i<=n; i++) {
		scanf("%d", &t[i]);
	}
	t[0] = -1e9;
	dp[0].insert(0);
	for (int i = 1; i<=n; i++) {
		if (i >= 2 && t[i]-t[i-1] < 2000 && t[i-1]-t[i-2] > 1000)
			combine(i, i-2);
		if (i >= 3 && t[i]-t[i-1] < 2000 && t[i-1]-t[i-2] < 2000 & t[i-2]-t[i-3] > 1000)
			combine(i, i-3);
		//printf("dp[%d] = %d, %d\n", i, dp[i].first, dp[i].second);
	}
	if (dp[n].size() == 0)
		printf("Impossible");
	else if (dp[n].size() > 1)
		printf("Ambiguous");
	else {
		int i = *dp[n].begin();
		int j = (n-2*i)/3;
		printf("Cars without trailers: %d\nCars with trailers: %d\n", i, j);
	}
}
