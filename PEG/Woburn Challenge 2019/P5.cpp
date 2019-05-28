#include <bits/stdc++.h>
using namespace std;
#define pi pair<int, int>
#define query pair<pi, pi>

vector<pi> adj[400005];
vector<query> queries;
int ans[4000005], stop[400005], go[400005], skip[400005], changed[500], B = 500;

int find(int c) {
	if (skip[c] == c)
		return c;
	return find(skip[c]);
}

int main() {
	// freopen("data.txt", "r", stdin);
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n - 1; i++) {
		int x, y, l;
		scanf("%d %d %d", &x, &y, &l);
		x--;
		y--;
		queries.push_back(query(pi(-l, 0), pi(x, y)));
	}
	for (int i = 0; i < k; i++) {
		int c, h;
		scanf("%d %d", &c, &h);
		c--;
		queries.push_back(query(pi(-h, 1), pi(c, i)));
	}
	sort(queries.begin(), queries.end());
	for (int i = 0; i < n; i++) {
		stop[i] = i;
		go[i] = i;
		skip[i] = i;
	}
	for (query q : queries) {
		if (q.first.second == 0) {
			int a = q.second.first;
			int b = q.second.second;
			if (a > b)
				swap(a, b);
			// printf("a = %d, b = %d, h = %d, go[a] = %d, skip[a] = %d\n", a, b, q.first.first, go[a], skip[a]);
			if (b > go[a]) {
				// for (int i = (a / B) * B; i < (a / B + 1) * B; i++) {
				// 	printf("go[%d] = %d, skip[%d] = %d\n", i, go[i], i, skip[i]);
				// }
				go[a] = b;
				if (b / B == a / B)
					skip[a] = skip[b];
				else
					skip[a] = b;
				// printf("go[a] = %d, skip[a] = %d\n", go[a], skip[a]);
				memset(changed, 0, sizeof changed);
				changed[a % B] = 1;
				for (int i = a - 1; i >= (a / B) * B; i--) {
                    // printf("i = %d, go[i] = %d, skip[i] = %d\n", i, go[i], skip[i]);
					if (go[i] / B == i / B) {
						if (changed[go[i] % B]) {
                            // printf("Changed!\n");
							skip[i] = skip[go[i]];
                            changed[i%B] = 1;
						}
					}
				}
			}
            // printf("Done\n");
			// for (int i = (a / B) * B; i < (a / B + 1) * B; i++) {
			// 	printf("go[%d] = %d, skip[%d] = %d\n", i, go[i], i, skip[i]);
			// }
		}
		else {
			int c = q.second.first;
			// printf("Query %d: C = %d, H = %d\n", q.second.second, c, q.first.first);
			while (skip[c] != c) {
				// assert(skip[skip[c]]/B > c/B);
				c = skip[c];
			}
			ans[q.second.second] = c;
            // printf("ans = %d\n", c);
		}
	}
	for (int i = 0; i < k; i++) {
		printf("%d\n", ans[i] + 1);
	}
	// for (int i = 0; i < n; i++) {
	// 	printf("go[%d] = %d, skip[%d] = %d\n", i, go[i], i, skip[i]);
	// }
}