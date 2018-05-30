#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

vector<int> G[100001];

int S, T, N, M;

int parent[100001];
int state[100001];
vector<int> stack;
unordered_map<int, unordered_set<int> > edgesInCycle;

bool cycleOverlap(int w, int v)
{
	while (v != w)
	{
		if (edgesInCycle[v].find(parent[v]) != edgesInCycle[v].end())
			return true;
		edgesInCycle[v].insert(parent[v]);
		v = parent[v];
	}
	return false;
}

//true iff G contains cycles that overlap
bool flask()
{
	if (M >= 2 * N - 3 && N >= 4)
		return true;
	stack.reserve(N);
	stack.push_back(1);

	while (!stack.empty())
	{
		int v = stack.back();
		if (state[v] != 0) stack.pop_back();
		else
		{
			bool allChildrenChecked = true;
			for (const int &w : G[v])
			{
				if (state[w] == 0) //tree edge
				{
					parent[w] = v;
					stack.push_back(w);
					allChildrenChecked = false;
				}
				else if (state[w] == 1 && w != parent[v] && cycleOverlap(w, v)) //back edge
					return true;
			}
			if (allChildrenChecked)
			{
				state[v] = 2;
				stack.pop_back();
			}
			else state[v] = 1;
		}
	}
	return false;
}

//true iff G contains a cycle of length >= 4
//or two cycles of length 3 that overlap
bool sun()
{
	stack.reserve(N);
	stack.push_back(1);

	while (!stack.empty())
	{
		int v = stack.back();
		if (state[v] != 0) stack.pop_back();
		else
		{
			bool allChildrenChecked = true;
			for (const int &w : G[v])
			{
				if (state[w] == 0) //tree edge
				{
					parent[w] = v;
					stack.push_back(w);
					allChildrenChecked = false;
				}
				else if (state[w] == 1 && w != parent[v]) //back edge
				{
					if (w != parent[parent[v]]) return true;
					else if (cycleOverlap(w, v)) return true;
				}
			}
			if (allChildrenChecked)
			{
				state[v] = 2;
				stack.pop_back();
			}
			else state[v] = 1;
		}
	}
	return false;
}

bool checkCycle(int w, int v)
{
	vector<int> cycle;
	int cycleLength = 0;
	int tmp = v;
	do
	{
		cycle.push_back(tmp);
		cycleLength++;
		tmp = parent[tmp];
	} while (tmp != v);

	for (int index_a = 1; index_a < cycleLength; index_a++)
	{
		int a = cycle[index_a];
		if (G[a].size() < 3) continue;
		for (int index_b = 0; index_b < index_a; index_b++)
		{
			int b = cycle[index_b];
			if (G[b].size() < 3) continue;
			for (const int &v1 : G[a])
			{
				if ((a == parent[v1] || v1 == parent[a]) && (find(cycle.begin(), cycle.end(), v1) != cycle.end())) continue;
				for (const int &v2 : G[b])
				{
					if ((b == parent[v2] || v2 == parent[b]) && (find(cycle.begin(), cycle.end(), v2) != cycle.end())) continue;

					//checks if G could have originated from fox graph
					if (v1 != v2)
					{
						if (find(cycle.begin(), cycle.end(), v1) != cycle.end() && find(cycle.begin(), cycle.end(), v2) != cycle.end())
						{
							if (cycleLength > 4) return true;
						}
						else return true;
					}
					else if (cycleLength >= 5)
						return true;
					else if (cycleLength == 4 && (parent[a] == b || parent[b] == a))
						return true;
				}
			}
		}
	}
	return false;
}

//true iff checkCycle returns true
bool fox()
{
	stack.reserve(N);
	stack.push_back(1);

	while (!stack.empty())
	{
		int v = stack.back();
		if (state[v] != 0) stack.pop_back();
		else
		{
			bool allChildrenChecked = true;
			for (const int &w : G[v])
			{
				if (state[w] == 0) //tree edge
				{
					parent[w] = v;
					stack.push_back(w);
					allChildrenChecked = false;
				}
				else if (state[w] == 1 && w != parent[v]) //back edge
				{
					int parent_w = parent[w];
					parent[w] = v; //temporary
					if (checkCycle(w, v)) return true;
					parent[w] = parent_w;
				}
			}
			if (allChildrenChecked)
			{
				state[v] = 2;
				stack.pop_back();
			}
			else state[v] = 1;
		}
	}
	return false;
}

int main()
{
	scanf("%d%d", &S, &T);
	for (int i = 0; i < T; i++)
	{
		scanf("%d %d", &N, &M);
		for (int j = 0; j < M; j++)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			G[a].push_back(b);
			G[b].push_back(a);
		}
		bool ans = false;
		switch (S)
		{
			case 1:
				memset(parent, 0, sizeof(parent[0]) * (N + 1));
				memset(state, 0, sizeof(state[0]) * (N + 1));
				stack.clear();
				edgesInCycle.clear();
				ans = flask();
				break;
			case 2:
				ans = (M != N - 1); //a connected graph is a tree iff M=N-1
				break;
			case 3:
				memset(parent, 0, sizeof(parent[0]) * (N + 1));
				memset(state, 0, sizeof(state[0]) * (N + 1));
				stack.clear();
				edgesInCycle.clear();
				ans = sun();
				break;
			case 4:
				for (int i = 1; i <= N; i++)
					if (G[i].size() >= 3)
					{
						ans = true; //true iff there exists a vertex with degree >= 3
						break;
					}
				break;
			case 5:
				memset(parent, 0, 4 * (N + 1));
				memset(state, 0, 4 * (N + 1));
				stack.clear();
				ans = fox();
				break;
		}
		if (ans) printf("YES\n");
		else printf("NO\n");
		for (int i=1;i<=N;i++)
			G[i].clear();
	}
	return 0;
}