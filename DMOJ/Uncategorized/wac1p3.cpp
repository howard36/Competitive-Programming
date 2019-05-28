#include <bits/stdc++.h>
using namespace std;
#define pi pair<int, int>

vector<int> adj[100005];
int p[100005], dp[100005], up[100005], ans[100005];
set<pi> s;

int main() {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 2; i <= n; i++) {
		scanf("%d", &p[i]);
		adj[p[i]].push_back(i);
	}
	for (int i = n; i > 0; i--) {
		dp[i] = 0;
		up[i] = -1;
		for (int v : adj[i]) {
			if (dp[v] > dp[i]) {
				dp[i] = dp[v];
				up[i] = v;
			}
		}
		dp[i]++;
	}
	s.insert(pi(dp[1], 1));
	for (int i = 0; i < k; i++) {
        if (s.size() == 0) {
            ans[i] = 0;
            continue;
        }
		ans[i] = s.rbegin()->first;
		int v = s.rbegin()->second;
		s.erase(--s.end());
		while (v != -1) {
			for (int u : adj[v]) {
				if (u != up[v]) {
					s.insert(pi(dp[u], u));
				}
			}
			v = up[v];
		}
	}
	for (int i = k; i < m; i++) {
		ans[i] = ans[i - k];
	}
	for (int i = 0; i < m; i++) {
		printf("%d%c", ans[i], (i == m - 1) ? '\n' : ' ');
	}
}