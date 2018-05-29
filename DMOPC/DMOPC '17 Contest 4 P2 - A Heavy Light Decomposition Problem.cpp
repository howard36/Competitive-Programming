#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
#define pb push_back
using namespace std;

int vs[1003], parent[1003];
vector<int> adj[1003];

void dfs(int u) {
	for (int i : adj[u]) {
		if (i != parent[u]) {
			parent[i] = u;
			dfs(i);
		}
	}
}

int main()
{
	int N, Q;
	scanf("%d%d", &N, &Q);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &vs[i]);
	}
	for (int i = 1; i < N; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].pb(b);
		adj[b].pb(a);
	}
	for (int i = 0; i < Q; i++) {
		int op, x, y;
		scanf("%d%d%d", &op, &x, &y);
		memset(parent, 0, sizeof parent);
		dfs(x);
		vector<int> vec;
		for (int v = y; v != x; v = parent[v]) {
			vec.pb(vs[v]);
		}
		vec.pb(x);
		sort(vec.begin(), vec.end());
		if (op == 1) {
			int sum = 0;
			for (int j : vec) {
				sum += j;
			}
			printf("%d\n", (int)round((double)sum / vec.size()));
		}
		else if (op == 2) {
			if (vec.size() % 2 == 1)
				printf("%d\n", vec[vec.size() / 2]);
			else {
				int m = vec[vec.size() / 2 - 1], n = vec[vec.size() / 2];
				printf("%d\n", (m+n+1)/2);
			}
		}
		else {
			int maxfreq = 0, mode = 0, last = 0, freq = 0;
			for (int j = 0; j < vec.size(); j++) {
				if (vec[j] != last) {
					freq = 1;
					last = vec[j];
				}
				else {
					freq++;
				}
				if (freq > maxfreq) {
					maxfreq = freq;
					mode = vec[j];
				}
			}
			printf("%d\n", mode);
		}
	}
    return 0;
}