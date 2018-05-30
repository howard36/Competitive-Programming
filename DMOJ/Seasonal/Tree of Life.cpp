#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

vector<int> adj[20004];
int parent[20004], depth[20004], idx[20004], sparse[40004][16];
vector<int> tour;
string DNA[20004];

void dfs(int node) {
	tour.push_back(node);
	for (const int& v : adj[node]) {
		dfs(v);
		tour.push_back(node);
	}
}

int LCA(int u, int v) {
	int a = idx[u], b = idx[v];
	if (a > b)
		swap(a, b);
	int diff = b - a, k = 0;
	while ((1 << k) <= diff) ++k;
	--k;
	if (depth[sparse[a][k]] < depth[sparse[b - (1 << k) + 1][k]])
		return sparse[a][k];
	else
		return sparse[b - (1 << k) + 1][k];
}

int main()
{
	int N;
	scanf("%d", &N);
	depth[1] = 0;
	for (int i = 2; i <= N; ++i) {
		scanf("%d", &parent[i]);
		depth[i] = depth[parent[i]] + 1;
		adj[parent[i]].push_back(i);
	}
	cin.sync_with_stdio(0);
	cin.tie(0);
	string s;
	for (int i = 1; i <= N; ++i) {
		cin >> s;
		DNA[i] = s;
	}
	dfs(1);
	for (int i = 0; i < tour.size(); ++i) {
		sparse[i][0] = tour[i];
	}
	for (int j = 1; (1<<j) < tour.size(); ++j) {
		for (int i = 0; i < tour.size() - (1 << j) + 1; ++i) {
			if (depth[sparse[i][j - 1]] <= depth[sparse[i + (1 << (j - 1))][j - 1]])
				sparse[i][j] = sparse[i][j - 1];
			else
				sparse[i][j] = sparse[i + (1 << (j - 1))][j - 1];
		}
	}
	for (int i = 0; i < tour.size(); ++i)
		idx[tour[i]] = i;

	int M = -1;
	for (int i = 1; i < N; ++i) {
		for (int j = i + 1; j <= N; ++j) {
			int k = LCA(i, j);
			if (i == k || j == k)
				continue;
			M = max(M, (int)min(DNA[i].length(), DNA[j].length()));
		}
	}
	printf("%d", M);
    return 0;
}