#include <bits/stdc++.h>
using namespace std;
#define pi pair<ll, ll>
#define mod 1000000007LL
#define ll long long

int v[500005], low[500005], num[500005], instack[500005], color[500005];
ll w[500005];
vector<int> adj[500005], adj2[500005];
vector<int> st;
int nums = 1, c = 0;
pi dp[500005], dp2[500005];

void dfs(int v) {
	num[v] = low[v] = nums++;
	instack[v] = 1;
	st.push_back(v);
	for (int u : adj[v]) {
		if (instack[u]) {
			low[v] = min(low[v], num[u]);
		}
		else {
            if (num[u] != -1)
                continue;
			dfs(u);
			low[v] = min(low[v], low[u]);
		}
	}
	if (num[v] == low[v]) {
		while (true) {
			int u = st.back();
			st.pop_back();
			color[u] = c;
			instack[u] = 0;
			if (u == v)
				break;
		}
		c++;
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}
	int a, b;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		a--, b--;
		if (a != b)
			adj[a].push_back(b);
	}

	memset(color, -1, sizeof color);
	memset(num, -1, sizeof num);
	for (int i = 0; i < n; i++) {
		if (color[i] == -1)
			dfs(i);
	}
	for (int i = 0; i < n; i++)
		w[color[i]] += v[i];

	for (int i = 0; i < n; i++)
		for (int j : adj[i])
            if (color[i] != color[j])
			    adj2[color[i]].push_back(color[j]);

	for (int i = 0; i < c; i++) {
		sort(adj2[i].begin(), adj2[i].end());
		auto newend = unique(adj2[i].begin(), adj2[i].end());
		adj2[i].erase(newend, adj2[i].end());
	}

	for (int i = color[n-1]; i <= color[0]; i++) {
		for (int j : adj2[i]) {
			if (w[i] + dp2[j].first > dp[i].first) {
				dp[i] = pi(w[i] + dp2[j].first, dp2[j].second);
			}
			else if (w[i] + dp2[j].first == dp[i].first) {
				dp[i].second += dp2[j].second;
				dp[i].second %= mod;
			}

			if (dp[j].first > dp2[i].first) {
				dp2[i] = dp[j];
			}
			else if (dp[j].first == dp2[i].first) {
				dp2[i].second += dp[j].second;
				dp2[i].second %= mod;
			}

			if (dp2[j].first > dp2[i].first) {
				dp2[i] = dp2[j];
			}
			else if (dp2[j].first == dp2[i].first) {
				dp2[i].second += dp2[j].second;
				dp2[i].second %= mod;
			}
		}

		if (w[i] > dp[i].first) {
			dp[i] = pi(w[i], 1);
		}
        else if (w[i] == dp[i].first)
            dp[i].second++;
	}

    pi x = dp[color[0]];
    pi y = dp2[color[0]];
    ll M = max(x.first, y.first), ways = 0;
    if (x.first == M)
        ways += x.second;
    if (y.first == M)
        ways += y.second;
    printf("%lld %lld\n", M, ways % mod);
}