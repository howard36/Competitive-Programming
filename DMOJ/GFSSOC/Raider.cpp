#include <bits/stdc++.h>
using namespace std;
#define pi pair<ll, ll>
#define mod 1000000007LL
#define ll long long

int v[500005], low[500005], num[500005], instack[500005], color[500005];
ll w[500005];
vector<int> adj[500005], adj2[500005];
set<int> front[500005], rev[500005];
vector<int> st, topo, topoq;
int nums = 0, c = 0;
pi edges[1500006];
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
		// printf("scc found, root = %d\n", v);
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
	freopen("data.txt", "r", stdin);
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}
	int a, b;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		a--, b--;
		edges[i] = pi(a, b);
        if (a != b)
		    adj[a].push_back(b);
	}
	memset(color, -1, sizeof color);
    memset(num, -1, sizeof num);
	for (int i = 0; i < n; i++) {
		if (color[i] == -1)
			dfs(i);
	}
	for (int i = 0; i < n; i++) {
		w[color[i]] += v[i];
		// printf("color[%d] = %d\n", i, color[i]);
	}
	// for (int i = 0; i<n; i++) {
	//     printf("num[%d] = %d\n", i, num[i]);
	// }
	for (int i = 0; i < m; i++) {
		tie(a, b) = edges[i];
        if (a == b)
            continue;
        a = color[a], b = color[b];
        if (a == b)
            continue;
		front[a].insert(b);
		rev[b].insert(a);
	}
	for (int i = 0; i < c; i++) {
        // printf("adj2[%d]: ", i);
		for (int j : front[i]) {
			adj2[i].push_back(j);
            // printf("%d, ", j);
        }
        // printf("\n");
	}
	for (int i = 0; i < c; i++) {
        if (front[i].size() == 0)
            topoq.push_back(i);
	}
    // printf("topoq: ");
    // for (int i = 0; i<topoq.size(); i++){
    //     printf("%d, ", topoq[i]);
    // }
    // printf("\n");
	while (!topoq.empty()) {
        int v = topoq.back();
        topoq.pop_back();
        topo.push_back(v);
        for (int u : rev[v]) {
            front[u].erase(front[u].find(v));
            if (front[u].size() == 0)
                topoq.push_back(u);
        }
    }
    // printf("topo: ");
    // for (int i = 0; i<topo.size(); i++){
    //     printf("%d ", topo[i]);
    // }
    // printf("\n");
    pi ans = pi(0, 0);
    for (int i : topo){
        dp[i] = pi(w[i], 1);
        dp2[i] = pi(0, 0);
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
		}
		if (dp[i].first > ans.first) {
			ans = dp[i];
		}
		else if (dp[i].first == ans.first) {
			ans.second += dp[i].second;
			ans.second %= mod;
		}
		// printf("dp[%d] = (%d, %d)\n", i, dp[i].first, dp[i].second);
		// printf("dp2[%d] = (%d, %d)\n", i, dp2[i].first, dp2[i].second);
	}
    printf("%lld %lld\n", ans.first, ans.second);
}