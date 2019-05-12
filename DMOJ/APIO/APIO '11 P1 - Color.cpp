#include <bits/stdc++.h>
using namespace std;

int val[200005], par[200005], sz[200005];

int find(int i) {
	if (par[i] == i)
		return i;
	return find(par[i]);
}

int parval(int i) {
	if (par[i] == i)
		return 0;
	return val[i] ^ parval(par[i]);
}

void join(int a, int b, int v) {
    v ^= parval(a) ^ parval(b);
	a = find(a);
	b = find(b);
	if (sz[a] > sz[b])
		swap(a, b);
	par[a] = b;
	sz[b] += sz[a];
	val[a] = v;
}

int main() {
    freopen("data.txt", "r", stdin);
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	int ans = n + m - 1;
	for (int i = 0; i < 200005; i++) {
		par[i] = i;
		sz[i] = 1;
	}
	for (int i = 0; i < k; i++) {
		int x, y, v;
		scanf("%d %d %d", &x, &y, &v);
		x += 1e5;
		if (find(x) == find(y)) {
			if (parval(x) ^ parval(y) ^ v) {
				printf("0");
				return 0;
			}
		}
		else {
			join(x, y, v);
			ans--;
		}
	}
	int power = 1;
	while (ans--) {
		power = (2 * power) % 1000000000;
	}
	printf("%d\n", power);
}