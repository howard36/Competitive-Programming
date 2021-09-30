#pragma GCC optimize("Ofast")
#pragma GCC target("avx")


#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int, int>
#define ppi pair<int, pi>

int a[300][300], C, color[300][300], d[300][300];
vector<pi> adj[300][300];
set<ppi> s;

void fill(int i, int j) {
	color[i][j] = C;
	for (pi &p : adj[i][j]) {
		int x = p.first, y = p.second;
		if (color[x][y] == 0)
			fill(x, y);
	}
}

inline int dist(pi a, pi b) {
	return abs(a.first-b.first) + abs(a.second-b.second);
}

int Astar(int sx, int sy, int ex, int ey) {
	s.clear();
	pi S = pi(sx, sy), E = pi(ex, ey);
	memset(d, 0x3f3f3f3f, sizeof d);
	s.insert(ppi(dist(S, E), S));
	d[sx][sy] = 0;
	while (!s.empty()) {
		pi v = s.begin()->second;
		s.erase(s.begin());
		int vx = v.first, vy = v.second;
		if (v == E)
			return d[vx][vy];
		for (pi &u : adj[vx][vy]) {
			int x = u.first, y = u.second;
			if (d[vx][vy] + 1 < d[x][y]) {
				d[x][y] = d[vx][vy] + 1;
				s.insert(ppi(d[x][y] + dist(E, u), u));
			}
		}
	}
	return d[ex][ey];
}

int main() {
	int n, q;
	char c;
	scanf("%d %d", &n, &q);
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++) {
			scanf(" %c", &c);
			if (c == '.')
				a[i][j] = 1;
		}
	}
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++) {
			if (a[i][j] == 0)
				continue;
			if (i > 0 && a[i-1][j])
				adj[i][j].push_back(pi(i-1, j));
			if (j > 0 && a[i][j-1])
				adj[i][j].push_back(pi(i, j-1));
			if (i < n-1 & a[i+1][j])
				adj[i][j].push_back(pi(i+1, j));
			if (j < n-1 && a[i][j+1])
				adj[i][j].push_back(pi(i, j+1));
		}
	}
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++) {
			if (color[i][j] == 0 && a[i][j]) {
				C++;
				fill(i, j);
			}
		}
	}

	while (q--) {
		int x1, x2, y1, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		x1--;
		y1--;
		x2--;
		y2--;
		if (a[x1][y1] * a[x2][y2] == 0) {
			printf("-1\n");
			continue;
		}
		if (color[x1][y1] != color[x2][y2]) {
			printf("-1\n");
			continue;
		}
		printf("%d\n", Astar(x1, y1, x2, y2));
	}
}
