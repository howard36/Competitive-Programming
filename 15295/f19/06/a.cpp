#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int, int>

vector<int> adj[200005];
int ord[200005], pos[200005], bfs[200005], vis[200005];
queue<int> q;
int B = 0;

bool cmp(int a, int b) {
	return pos[a] < pos[b];
}

int main() {
	int n, a, b;
	scanf("%d", &n);
	for (int i = 0; i<n-1; i++) {
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 1; i<=n; i++) {
		scanf("%d", &ord[i]);
		pos[ord[i]] = i;
	}
	q.push(1);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		bfs[B++] = v;
		vis[v] = 1;
		sort(adj[v].begin(), adj[v].end(), cmp);
		for (int i : adj[v]) {
			if (!vis[i]) {
				q.push(i);
			}
		}
	}	
	for (int i = 1; i<=n; i++) {
		if (ord[i] != bfs[i-1]) {
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
}
