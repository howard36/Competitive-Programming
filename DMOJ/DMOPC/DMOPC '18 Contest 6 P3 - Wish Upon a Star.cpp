#include <bits/stdc++.h>
using namespace std;

vector<int> adj[200005];
int covered[200005];

void cover(int i) {
	covered[i] = 1;
	for (int k : adj[i]) {
		if (!covered[k])
			cover(k);
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int a, b;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (!covered[i]) {
			cover(i);
			cnt++;
		}
	}
	if (m > n - cnt + 1) {
		printf("NO");
	}
	else {
		printf("YES");
	}
}