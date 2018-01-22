#include <cstdio>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <cstring>
#define pii pair<int,int>
using namespace std;

int N, S, D = 0, pointer;
vector<int> G[5001];
int parent[5001], covered[5001], tmpcovered[5001];
vector<pii> dist;

inline bool comp(pii x, pii y) { return x.second > y.second; }

void initDist(int v, int depth)
{
	dist.push_back(make_pair(v, depth));
	for (const int &child : G[v])
	{
		if (child != parent[v])
		{
			parent[child] = v;
			initDist(child, depth + 1);
		}
	}
}

void cover(int v, int range)
{
	covered[v] = 1; tmpcovered[v] = 1;
	if (range == 0)
		return;
	for (const int &neighbor : G[v])
		if (!tmpcovered[neighbor])
			cover(neighbor, range - 1);
}

bool findD()
{
	if (D == 0)
		return S == N;
	pointer = 0;
	memset(covered, 0, sizeof(covered));
	for (int s = 1; s <= S; s++)
	{
		int node = dist[pointer].first;
		for (int i = 0; i < D; i++)
		{
			if (node == 1)
				break;
			node = parent[node];
		}
		memset(tmpcovered, 0, sizeof(tmpcovered));
		cover(node, D);
		if (!covered[dist[pointer].first])
		    printf("%d %d %d\n", dist[pointer].second, pointer, s);
		/*
		if (node == 1)
		{
		    int notCovered = 0;
		    for (int i=1;i<=pointer;i++)
		        if (!covered[i])
		            ++notCovered;
		    if (notCovered > 0)
		        printf("%d %d %d\n", notCovered, pointer, s);
		}*/
		while (covered[dist[pointer].first])
		{
			++pointer;
			if (pointer >= N)
				return true;
		}
	}
	return false;
}

int main()
{
	scanf("%d%d", &N, &S);
	int u, v;
	for (int i = 1; i < N; i++)
	{
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	initDist(1, 0);
	sort(dist.begin(), dist.end(), comp);
	while (!findD() && D < 2525) { ++D; }
	printf("%d", D);
	return 0;
}