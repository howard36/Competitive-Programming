#include <bits/stdc++.h>
#define pi pair<int,int>
#define mp make_pair
#define edge pair<int, pi>
#define query pair<pi, pi>
using namespace std;

int link[100005], sz[100005];
vector<edge> edges;
vector<query> queries;

int find(int x) {
	while (x != link[x]) x = link[x];
	return x;
}

void unite(int a, int b) {
	a = find(a);
	b = find(b);
	if (sz[a] < sz[b]) swap(a, b);
	sz[a] += sz[b];
	link[b] = a;
}

bool sortedgedecreasing(edge a, edge b) {
	return a.first > b.first;
}

bool sortqueriesdecreasing(query a, query b) {
	return a.first.first > b.first.first;
}

bool sortbyid(query a, query b) {
	return a.second.first < b.second.first;
}

int main()
{
	FILE *fin = fopen("mootube.in", "r");
	FILE *fout = fopen("mootube.out", "w");
	int N, Q;
	fscanf(fin, "%d%d", &N, &Q);
	for (int i = 1; i <= N; i++) link[i] = i;
	for (int i = 1; i <= N; i++) sz[i] = 1;

	int p, q, r;
	for (int i = 1; i < N; i++) {
		fscanf(fin, "%d%d%d", &p, &q, &r);
		edges.push_back(make_pair(r, make_pair(p, q)));
	}
	sort(edges.begin(), edges.end(), sortedgedecreasing);
	int v, k;
	for (int i = 0; i < Q; i++) {
		fscanf(fin, "%d%d", &k, &v);
		queries.push_back(mp(mp(k, v), mp(i, 0)));
	}
	sort(queries.begin(), queries.end(), sortqueriesdecreasing);

	int e = 0;
	for (int q = 0; q < Q; q++) {
		k = queries[q].first.first;
		v = queries[q].first.second;
		while (e < N - 1 && edges[e].first >= k) {
			// add edge e
			unite(edges[e].second.first, edges[e].second.second);
			e++;
		}
		queries[q].second.second = sz[find(v)] - 1;
	}

	sort(queries.begin(), queries.end(), sortbyid);

	for (int i = 0; i < Q; i++) {
		fprintf(fout, "%d\n", queries[i].second.second);
	}

    return 0;
}
