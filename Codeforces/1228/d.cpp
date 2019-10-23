#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007LL

int c[100005];
vector<int> adj[100005], col[3];
ll n, m;

int main() {
	scanf("%lld %lld", &n, &m);
	for (int i = 0; i<m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		a--;
		b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i : adj[0])
		c[i] = 1;
	if (adj[0].size() <= 1) {
		printf("-1");
		return 0;
	}
	int s = adj[0][0];
	for (int i : adj[s]) {
		if (c[i] == 1)
			c[i] = 2;
	}
	for (int i = 0; i<n; i++)
		col[c[i]].push_back(i);
	assert(col[0].size() + col[1].size() + col[2].size() == n);
	for (int i = 0; i<3; i++) {
		if (col[i].size() == 0) {
			printf("-1");
			return 0;
		}
	}
	for (int i = 0; i<n; i++) {
		if (adj[i].size() != n - col[c[i]].size()) {
			printf("-1");
			return 0;
		}
		for (int j : adj[i]) {
			if (c[i] == c[j]) {
				printf("-1");
				return 0;
			}
		}
	}
	for (int i = 0; i<n; i++)
		printf("%d ", c[i]+1);
}
