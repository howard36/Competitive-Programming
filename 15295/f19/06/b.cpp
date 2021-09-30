#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int, int>

int a[1000006], adj[102][102], dist[102][102], vis[102];
int n;
vector<int> ans;



void bfs(int s) {
	memset(vis, 0, sizeof vis);
	queue<int> q;
	q.push(s);
	dist[s][s] = 0;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		vis[v] = 1;
		for (int i = 0; i<n; i++) {
			if (adj[v][i]) {
				if (dist[s][v] + 1 < dist[s][i]) {
					dist[s][i] = dist[s][v] + 1;
					q.push(i);
				}
			}
		}
	}
}


int main() {
	scanf("%d", &n);
	char c;
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++) {
			scanf(" %c", &c);
			adj[i][j] = c-'0';
		}
	}
	int m;
	scanf("%d", &m);
	for (int i = 0; i<m; i++) {
		scanf("%d", &a[i]);
		a[i]--;
	}
	memset(dist, 0x3f3f3f3f, sizeof dist);
	for (int i = 0; i<n; i++)
		bfs(i);

	int last = a[0];
	ans.push_back(0);
	for (int i = 1; i<m-1; i++) {
		if (dist[last][a[i]] + dist[a[i]][a[i+1]] > dist[last][a[i+1]]) {
			ans.push_back(i);
			last = a[i];
		}
	}
	ans.push_back(m-1);
	printf("%d\n", ans.size());
	for (int i : ans)
		printf("%d ", a[i]+1);
}
