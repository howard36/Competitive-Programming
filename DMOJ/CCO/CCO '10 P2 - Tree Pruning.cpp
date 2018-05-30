#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;
vector<int> adj[302];
int val[302];
int dp[302][602];

void solve(int v) {
	for (int child : adj[v])
		solve(child);

	dp[v][300] = 1;
	if (adj[v].size() == 0) {
		dp[v][val[v] + 300] = 0;
	}
	else if (adj[v].size() == 1) {
		int child = adj[v][0];
		for (int d = 0; d <= 600; d++) {
			if (dp[child][d] < INF) {
				dp[v][val[v] + d] = min(dp[v][val[v] + d], dp[child][d]);
			}
		}
	}
	else {
		int child1 = adj[v][0], child2 = adj[v][1];
		for (int d1 = 0; d1 <= 600; d1++) {
			for (int d2 = 0; d2 <= 600; d2++) {
				if (dp[child1][d1] < INF && dp[child2][d2] < INF) {
					dp[v][val[v] + d1 + d2 - 300] = min(dp[v][val[v] + d1 + d2 - 300], dp[child1][d1] + dp[child2][d2]);
				}
			}
		}
	}
}

int main()
{
	int N, D, id, color, numchild, child;
	scanf("%d%d", &N, &D);
	for (int i = 0; i < N; i++) {
		scanf("%d%d%d", &id, &color, &numchild);
		val[id] = 2 * color - 1;
		for (int j = 0; j < numchild; j++) {
			scanf("%d", &child);
			adj[id].push_back(child);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= 600; j++) {
			dp[i][j] = INF;
		}
	}
	solve(0);/*
	for (int v = 0; v < N; v++) {
		for (int d = 0; d <= 600; d++) {
			if (dp[v][d] < INF) {
				printf("dp[%d][%d] = %d\n", v, d - 300, dp[v][d]);
			}
		}
	}*/
	if (dp[0][D + 300] == INF)
		printf("-1");
	else
		printf("%d", dp[0][D + 300]);
    return 0;
}