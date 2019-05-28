#include <bits/stdc++.h>
using namespace std;

map<int, set<int>> adj;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (a == b) {
			printf("NOT SIMPLE\n");
			return 0;
		}
		else if (a > b)
			swap(a, b);
		if (adj.find(a) != adj.end()) {
			if (adj[a].find(b) != adj[a].end()) {
				printf("NOT SIMPLE\n");
				return 0;
			}
            else {
                adj[a].insert(b);
            }
		}
        else {
            adj[a] = set<int>();
            adj[a].insert(b);
        }
	}
    printf("SIMPLE\n");
}