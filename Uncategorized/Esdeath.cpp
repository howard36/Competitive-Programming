#include <cstdio>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <cstring>
#define pii pair<int,int>
using namespace std;

int N, S, D = 0, pointer, coverCount, soldiersUsed;
vector<int> G[5001];
int parent[5001], covered[5001], tmpcovered[5001];
vector<pii> dist;

inline bool comp(pii x, pii y) { return x.second > y.second; }

void initDist(int v, int depth)
{
	dist.push_back(make_pair(v,depth));
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
//	printf("Covering %d with range %d\n", v, range);
	if (!covered[v])
		++coverCount;
	covered[v] = 1; tmpcovered[v] = 1;
	if (range == 0)
		return;
	for (const int &neighbor : G[v])
		if (!tmpcovered[neighbor])
			cover(neighbor, range - 1);
}

bool findD()
{
//	printf("Finding D: %d\n", D);
	if (D == 0)
		return S == N;
	pointer = 0; coverCount = 0; soldiersUsed = 0;
	memset(covered, 0, 5001);
	bool stopLoop = false;
	while (coverCount < N)
	{
		if (soldiersUsed >= S)
			return false;
		while (covered[dist[pointer].first])
		{
			++pointer;
			if (pointer >= N)
			{
				stopLoop = true;
				break;
			}
		}
		if (stopLoop)
			return true;
		int node = dist[pointer].first;
		for (int i = 0; i < D; i++)
		{
			if (node == 1)
				break;
			node = parent[node];
		}
		memset(tmpcovered, 0, 5001);
		cover(node, D);
		++soldiersUsed;
	}
	return true;
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
	while (!findD() && D < N) { ++D; }
	printf("%d", D);
//	while (scanf("%d: %d", D, findD())) { ++D; }
	/*
	for (int i = 0; i < N; i++)
	{
		D = i;
		if (findD())
			printf("%d is possible", D);
		else
			printf("%d is impossible", D);
	}*/
    return 0;
}