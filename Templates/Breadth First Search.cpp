#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100005];
int parent[100005];
queue<int> Q;
unordered_set<int> visited;

void BFS(int root, int goal) {
	Q.push(root);
	while (!Q.empty()) {
		int current = Q.front();
		Q.pop();
		if (current == goal)
			return;
		for (const int &child : G[current]) {
			if (visited.find(child) == visited.end()) {//if tree, use child != parent[current]
				visited.insert(child);
				parent[child] = current;
				Q.push(child);
			}
		}
	}
}
