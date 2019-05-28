#include <bits/stdc++.h>
using namespace std;

vector<int> adj[302], pos;
int c[302], depth[302], par[302];
int n, a, b;

bool subtask1() {
	// for (int i = 0; i < n; i++) {
	// 	if (depth[i] == n - 1)
	// 		return true;
	// }
	// return false;
	// bool startFound = false;
	// int start, end;
	for (int i = 0; i < n; i++) {
		if (adj[i].size() > 2)
			return false;
	}
	return true;
	//     if (adj[i].size() == 1){
	//         if (!startFound){
	//             startFound = true;
	//             start = i;
	//             ord[i] = 0;
	//         }
	//         else {
	//             end = i;
	//             ord[i] = n-1;
	//         }
	//     }
	// }
	// int v = adj[start][0], p = start;
	// for (int i = 1; i < n-2; i++) {
	//     depth
	// }
	// return true;
}

int dfs(int v, int p, int d) {
	par[v] = p;
	depth[v] = d;
	for (int u : adj[v]) {
		if (u == p)
			continue;
		dfs(u, v, d + 1);
	}
}

int main() {
	scanf("%d %d %d", &n, &a, &b);
	a--;
	b--;
	for (int i = 0; i < n; i++) {
		char chr;
		scanf(" %c", &chr);
		c[i] = chr - '0';
	}
	c[a] = c[b] = 1;
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		x--;
		y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	if (subtask1()) {
		int root;
		for (int i = 0; i < n; i++) {
			if (adj[i].size() == 1)
				root = i;
		}
		// printf("root = %d\n", root);
		dfs(root, -1, 0);
		// for (int i = 0; i < n; i++) {
		// 	printf("depth[%d] = %d\n", i, depth[i]);
		// }
		for (int i = 0; i < n; i++) {
			if (c[i]) {
				pos.push_back(depth[i]);
			}
		}
		sort(pos.begin(), pos.end());
		// for (int i = 0; i < pos.size(); i++) {
		// 	printf("pos[%d] = %d\n", i, pos[i]);
		// }
		int pa = depth[a], pb = depth[b], ans = 1e9;
        int l = pos[0], r = pos[pos.size()-1];
		if (pa > pb)
			swap(pa, pb);
        // printf("%d %d %d %d\n", pa, pb, l, r);
		for (int i = 0; i < pos.size() - 1; i++) {
			ans = min(ans, max(max(pa, pos[i]) - l, r - min(pb, pos[i + 1])));
			// printf("i = %d, l = %d, r = %d\n", i, max(pa, pos[i]) - l, r - min(pb, pos[i+1]));
		}
		printf("%d", 2 * ans);
	}
}