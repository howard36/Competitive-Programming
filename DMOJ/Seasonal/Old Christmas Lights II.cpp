#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx") 

#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#define ll long long
using namespace std;

int c[50004];
vector<int> brightnesses;
vector<int> adj[50004];
int parent[50004], depth[50004], idx[50004], sparse[100005][18];
unordered_map<ll, int> found;
vector<int> tour;

inline ll hash1(int u, int v) { return 50000LL * u + v; }

void dfs(int node) {
	tour.push_back(node);
	for (const int& v : adj[node]) {
		if (v != parent[node]) {
			parent[v] = node;
			depth[v] = 1 + depth[node];
			dfs(v);
			tour.push_back(node);
		}
	}
}

int LCA(int u, int v) {
	int a = idx[u], b = idx[v];
	if (a > b)
		swap(a, b);
	int diff = b - a;
	int k = 0; // 31 - __builtin_clz(diff);
	while ((1 << k) <= diff) ++k;
	--k;
	if (depth[sparse[a][k]] < depth[sparse[b - (1 << k) + 1][k]])
		return sparse[a][k];
	else
		return sparse[b - (1 << k) + 1][k];
}
/*
void BFS(int root, int goal)
{
	queue<int> que;
	que.push(root);
	while (!que.empty())
	{
		int current = que.front();
		que.pop();
		if (current == goal)
			return;
		for (const int &child : adj[current])
		{
			if (child != parent[current])
			{
				parent[child] = current;
				que.push(child);
			}
		}
	}
}

void dfs(int cur, int end) {
	for (int v : adj[cur]) {
		if (v != parent[cur]) {
			parent[v] = cur;
			if (v == end)
				return;
			dfs(v, end);
		}
	}
}
*/
int main()
{
	int N, Q, a, b, u, v;
	scanf("%d%d", &N, &Q);
	for (int i = 1; i <= N; ++i)
		scanf("%d", &c[i]);
	for (int i = 1; i < N; ++i) {
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(N/2);
	for (int i = 0; i < tour.size(); ++i) {
		sparse[i][0] = tour[i];
	}
	for (int j = 1; (1 << j) < tour.size(); ++j) {
		for (int i = 0; i < tour.size() - (1 << j) + 1; ++i) {
			if (depth[sparse[i][j - 1]] <= depth[sparse[i + (1 << (j - 1))][j - 1]])
				sparse[i][j] = sparse[i][j - 1];
			else
				sparse[i][j] = sparse[i + (1 << (j - 1))][j - 1];
		}
	}
	for (int i = 0; i < tour.size(); ++i)
		idx[tour[i]] = i;

	for (int i = 0; i < Q; ++i) {
		scanf("%d%d", &u, &v);
		if (u > v)
			swap(u, v);
		if (found.find(hash1(u, v)) != found.end())	{
			printf("%d\n", found[hash1(u, v)]);
			continue;
		}
//		memset(parent, 0, sizeof(parent));
//		BFS(u, v);
//		brightnesses.clear();
		vector<int> cs;
		int lca = LCA(u, v);
		int node = u;
		while (node != lca) {
			cs.push_back(c[node]);
			node = parent[node];
		}
		node = v;
		while (node != lca) {
			cs.push_back(c[node]);
			node = parent[node];
		}
		cs.push_back(c[lca]);
		sort(cs.begin(), cs.end());
		int mindiff = 1000000009;
		for (int i = 0; i < cs.size() - 1; ++i) {
			if (cs[i + 1] - cs[i] < mindiff)
				mindiff = cs[i + 1] - cs[i];
		}
		printf("%d\n", mindiff);
		found[hash1(u, v)] = mindiff;
	}
    return 0;
}