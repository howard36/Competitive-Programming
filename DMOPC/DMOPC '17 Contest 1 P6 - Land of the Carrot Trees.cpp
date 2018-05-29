#include <cstdio>
#include <vector>
#include <queue>
#include <unordered_set>
#include <cstring>
#include <algorithm>
#define pi pair<int,int>
#define pb push_back
#define mp make_pair
using namespace std;

vector<pi> G[100001];
int parent[100001];
queue<int> Q;
int Xor[100001];

int BFS(int root, int goal)
{
    while (!Q.empty()) Q.pop();
	memset(parent, 0, sizeof(parent));
	Xor[root] = 0;
	Q.push(root);
	while (!Q.empty())
	{
		int current = Q.front();
		Q.pop();
		if (current == goal)
			return Xor[current];
		for (const pi &edge : G[current])
		{
			int child = edge.first;
			if (child != parent[current])
			{
				parent[child] = current;
				Xor[child] = Xor[current] ^ edge.second;
				Q.push(child);
			}
		}
	}
	return -1;
}

struct CompareFirst
{
	CompareFirst(int val) : val_(val) {}
	bool operator()(const std::pair<int, char>& elem) const
	{
		return val_ == elem.first;
	}
private:
	int val_;
};


int main()
{
	int N, Q, a, b, c; char op;
	scanf("%d %d", &N, &Q);
	for (int i = 1; i < N; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		G[a].pb(mp(b, c));
		G[b].pb(mp(a, c));
	}
	for (int i = 0; i < Q; i++)
	{
		scanf(" %c", &op);
		if (op == 'A')
		{
			scanf("%d %d %d", &a, &b, &c);
			G[a].pb(mp(b, c));
			G[b].pb(mp(a, c));
		}
		else if (op == 'R')
		{
			scanf("%d %d", &a, &b);
			auto it = find_if(G[a].begin(), G[a].end(), CompareFirst(b));
			if (it != G[a].end())
				G[a].erase(it);
			it = find_if(G[b].begin(), G[b].end(), CompareFirst(a));
			if (it != G[b].end())
				G[b].erase(it);
		}
		else
		{
			scanf("%d %d", &a, &b);
			printf("%d\n", BFS(a, b));
		}
	}
	return 0;
}