#include <bits/stdc++.h>
using namespace std;
#define mod 998244353LL
#define ll long long

vector<int> adj[102];
int c[102];
ll dp[102][102][3][3], t[102][3][3];
int n, k;

void dfs(int v, int p) {
	dp[v][1][c[v]][1 - c[v]] = 1;
	for (int u : adj[v]) {
		if (u == p)
			continue;
		dfs(u, v);
		for (int k1 = 0; k1 <= k; k1++) {
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					t[k1][i][j] = dp[v][k1][i][j];
					dp[v][k1][i][j] = 0;
				}
			}
		}
		for (int i1 = 0; i1 < 3; i1++) {
			for (int j1 = 0; j1 < 3; j1++) {
				for (int k1 = 0; k1 <= k; k1++) {
					for (int i2 = 0; i2 < 3; i2++) {
						for (int j2 = 0; j2 < 3; j2++) {
							for (int k2 = 0; k1 + k2 <= k; k2++) {
								dp[v][k1 + k2][min(2, i1 + i2)][min(2, j1 + j2)] += t[k1][i1][j1] * dp[u][k2][i2][j2];
								dp[v][k1 + k2][min(2, i1 + i2)][min(2, j1 + j2)] %= mod;
							}
						}
					}
				}
			}
		}
	}
	dp[v][0][0][0] = 1;
}

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		char chr;
		scanf(" %c", &chr);
		c[i] = (chr == 'B');
	}
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1, -1);
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = (ans + dp[i][k][2][2]) % mod;
	}
	printf("%lld\n", ans);
}