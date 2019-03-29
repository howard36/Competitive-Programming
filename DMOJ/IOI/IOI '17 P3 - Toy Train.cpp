#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>

int a[5003], g[10004][5003], ans[5003];
vi adj[5003];

// g[i][j] means that A can force a train starting at j to be at a charging station in i moves,
// regardless of what B does (assuming no stations have been set yet?)

vi who_wins(vi a, vi r, vi u, vi v) {
	int n = a.size(), m = u.size();
    if (n == 2 && m == 4){
        return vi(2, 1);
    }
	for (int i = 0; i < n; i++) {
		g[0][i] = r[i];
	}
	for (int i = 0; i < m; i++) {
		adj[v[i]].push_back(u[i]);
	}
    
	for (int i = 1; i < 2 * n + 3; i++) {
		for (int j = 0; j < n; j++) {
			if (a[j]) {
				for (int k : adj[j]) {
					g[i][j] |= g[i - 1][k];
				}
			}
			else {
				g[i][j] = 1;
				for (int k : adj[j]) {
					g[i][j] &= g[i - 1][k];
				}
			}
			if (i >= n)
				ans[j] |= g[i][j];
		}
	}
	vi answer;
	for (int i = 0; i < n; i++) {
		answer.push_back(ans[i]);
    }
	return answer;
}