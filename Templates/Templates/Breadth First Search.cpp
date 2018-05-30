#include "stdafx.h"

#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

vector<int> G[10000];
int parent[10000];
queue<int> Q;
unordered_set<int> visited;

int BFS(int root, int goal)
{
	Q.push(root);
	while (!Q.empty())
	{
		int current = Q.front();
		Q.pop();
		if (current == goal)
			return current;
		for (const int &child : G[current])
		{
			if (visited.find(child) == visited.end()) //if tree, use child != parent[current]
			{
				visited.insert(child);
				parent[child] = current;
				Q.push(child);
			}
		}
	}
}