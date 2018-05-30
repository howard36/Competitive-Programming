#include <algorithm>
#include <cstdio>
using namespace std;

int v[200005], link[200005], sz[200005];

int find(int x) {
	while (x != link[x]) x = link[x];
	return x;
}

void unite(int a, int b) {
	a = find(a);
	b = find(b);
	if (sz[a] < sz[b])
		swap(a, b);
	sz[a] += sz[b];
	link[b] = a;
}

int main() {
	int N, Q, M, p, q;
	scanf("%d%d%d", &N, &M, &Q);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &v[i]);
	}
	bool subtask3 = false;
	for (int k = 0; k < 31; k++) {
		if (M == (1 << k) - 1)
			subtask3 = true;
	}
	if (subtask3) {
		for (int i = 0; i < Q; i++) {
			scanf("%d%d", &p, &q);
			if ((v[p] ^ v[q]) <= M)
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
	else {
		for (int i = 1; i <= N; i++) {
			link[i] = i;
			sz[i] = 1;
		}
		for (int i = 1; i < N; i++) {
			for (int j = i + 1; j <= N; j++) {
				if ((v[i] ^ v[j]) <= M && find(i) != find(j)) {
					unite(i, j);
				}
			}
		}
		for (int i = 0; i < Q; i++) {
			scanf("%d%d", &p, &q);
			if (find(p) == find(q))
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
}