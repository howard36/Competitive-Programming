#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int, int>
#define ppi pair<int, pi>

int a[1003], b[1003], cc[2003][2003];
int par[2003], sz[2003], ext[2003];
int A, B, C;
ppi edges[200005];


int find(int i) {
	if (par[i] == i) return i;
	return par[i] = find(par[i]);
}

int merge(int i, int j) {
	printf("Merging %d, %d, ", i, j);
	i = find(i);
	j = find(j);
	if (i == j)
		return 0;
	int ret = 0;
	if (ext[i]*ext[j] < 0) {
		if (ext[i] < 0)
			ret = min(-ext[i], ext[j]);
		else
			ret = min(ext[i], -ext[j]);
	}
	if (sz[i] < sz[j])
		swap(i, j);
	ext[i] += ext[j];
	sz[i] += sz[j];
	par[j] = i;
	printf("returning %d\n", ret);
	return ret;
}

int main() {
	scanf("%d%d%d", &B, &A, &C);
	for (int i = 1; i<=B; i++) {
		scanf("%d", &b[i]);
	}
	for (int i = 1; i<=A; i++) {
		scanf("%d", &a[i]);	
	}
	for (int i = 0; i<C; i++) {
		int I, J, T;
		scanf("%d %d %d", &J, &I, &T);
		edges[i] = ppi(T, pi(I, J+A));
	}
	for (int i = 1; i <= A+B; i++) {
		par[i] = i;
		sz[i] = 1;
		if (i <= A)
			ext[i] = a[i];
		else
			ext[i] = -b[i-A];
	}
	sort(edges, edges+C);

	ll tot = 0;
	for (int i = 1; i <= B; i++)
		tot += b[i];
	for (int i = 0; i<C; i++) {
		tot -= merge(edges[i].second.first, edges[i].second.second);

		if (tot == 0) {
			printf("%d", edges[i].first);
			return 0;
		}
	}
	printf("-1\n");
}
