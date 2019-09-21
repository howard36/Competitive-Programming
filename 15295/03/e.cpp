#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int, int>
#define ppi pair<int, pi>

ppi edges[300005];
int dp[300005];
vector<pi> vec;

void update() {
	for (pi p : vec)
		dp[p.first] = max(dp[p.first], p.second);
	vec.clear();
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i<m; i++) 
		scanf("%d %d %d", &edges[i].second.first, &edges[i].second.second, &edges[i].first);
	sort(edges, edges+m);
	reverse(edges, edges+m);
	int last = 1e9;
	for (int i = 0; i<m; i++) {
		int u, v, w, l;
		tie(u, v) = edges[i].second;
		w = edges[i].first;
		if (w != last) {
			update();
			last = w;
		}
		vec.push_back(pi(u, dp[v]+1));
	}
	update();
	int ans = 0;
	for (int i = 1; i<=n; i++)
		ans = max(ans, dp[i]);
	printf("%d\n", ans);
}
