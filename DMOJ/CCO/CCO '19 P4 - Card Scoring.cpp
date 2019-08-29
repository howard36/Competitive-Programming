#include <bits/stdc++.h>
using namespace std;

double dp[1000006], power[1000006];
int a[1000006], f[1000006], c[1000006], last[1000006], back[1000006];
vector<int> s[1000006];
int k, n;

double ff(int i, int j) {
	return dp[j-1] + power[c[i]-c[j]+1];
}

double split(int j1, int j2) {
	double d1 = dp[j1-1] + power[c[j1] - 1];
	double d2 = dp[j2-1] + power[c[j2] - 1];
	double c1 = 2.0 * (c[j1] - 1);
	double c2 = 2.0 * (c[j2] - 1);
	return (d2 - d1) / (c2 - c1);
}

int main() {
	scanf("%d %d", &k, &n);
	if (k == 2) {
		printf("%d", n);
		return 0;
	}
    for (int i = 1; i<=n; i++)
        power[i] = pow(i, 0.5*k);
	for (int i = 1; i<=n; i++) {
		scanf("%d", &a[i]);
		f[a[i]]++;
		c[i] = f[a[i]];
	}
	dp[0] = 0;
	for (int i = 1; i<=n; i++) {
		while (s[a[i]].size() > 1) {
			int sz = s[a[i]].size();
			if (split(s[a[i]][sz-2], s[a[i]][sz-1]) < split(s[a[i]][sz-2], i))
				s[a[i]].pop_back();
			else
				break;
		}
		s[a[i]].push_back(i);
		while (s[a[i]].size() > 1) {
			int sz = s[a[i]].size();
			if (ff(i, s[a[i]][sz-2]) >= ff(i, s[a[i]][sz-1]))
				s[a[i]].pop_back();
			else
				break;
		}
		dp[i] = ff(i, s[a[i]].back());
	}
	printf("%.12lf", dp[n]);
}