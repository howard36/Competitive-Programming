#include <bits/stdc++.h>
using namespace std;

int p[500005], sz[500005];

int find(int a) {
	if (p[a] == a)
		return a;
	return (p[a] = find(p[a]));
}

void join(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) {
		if (sz[a] < sz[b])
			swap(a, b);
		p[b] = a;
		sz[a] += sz[b];
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		p[i] = i;
		sz[i] = 1;
	}
	for (int i = 0; i < m; i++) {
		int x, a, b;
		scanf("%d", &x);
		if (x > 0)
			scanf("%d", &a);
		for (int j = 0; j < x - 1; j++) {
			scanf("%d", &b);
			join(a, b);
		}
	}
	for (int i = 1; i <= n; i++) {
		// printf("p[%d] = %d\n", i, p[i]);
		printf("%d ", sz[find(i)]);
		// printf("%d\n", sz[find(i)]);
	}
}