#include <iostream>

#include <cstdio>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

#include <set>

int N;
int maxV;
int multiplicity[1000007];
unordered_set<int> odd;
unordered_set<int> even;
vector<int> G[1000001];

int parent[1000007];
int state[1000007];

unordered_map<int, int> backedges;
int cyclecount = 0;

bool cycle()
{
	vector<int> stack;
	stack.reserve(N);
	bool toReturn = false;
	for (int i = maxV; i > 0; i--)
		stack.push_back(i);
	
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
				else if (state[w] == 1) //back edge
				{
					if (w != parent[v])
					{
						toReturn = true;
						printf("Back Edge (%d, %d) (Cycle)\n", w, v);
						backedges[v] = w;
						cyclecount++;
					}
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
	return toReturn;
}

void printG()
{
	for (int i : {94395, 87508, 71068, 40755, 20955, 5548, 16892, 3885})
	{
		if (G[i].empty()) continue;
		cout << i << ": ";
		for (int j : G[i])
		{
			cout << j << ", ";
		}
		cout << "Parent: " << parent[i] << " ";
		cout << "Size: " << G[i].size() << "\n";
	}
}

int gcd(int a, int b)
{
	while (b != 0)
	{
		int t = b;
		b = a % b;
		a = t;
	}
	return a;
}

void PrintCycle(int v, int u)
{
	cout << "Cycle: ";
	do
	{
		cout << u << ", ";
		u = parent[u];
	} while (u != v && u != 0);
	cout << v << "\n";
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		int a;// = i + 1;
		scanf("%d", &a);
		multiplicity[a] += 1;
		maxV = max(maxV, a);
		if (a % 2 == 1) odd.insert(a);
		else if (a % 4 == 0) even.insert(a);
	}

	for (int m = 2; m < 1100; m++)
	{
		for (int n = m - 1; n > 0; n -= 2)
		{
			int a = m*m - n*n, b = 2 * m*n;
			if (gcd(m, n) == 1 && (odd.find(a) != odd.end()) && (even.find(b) != even.end()))
			{
				G[a].push_back(b);
				G[b].push_back(a);
			}
		}
	}

	int hasCycle = cycle();
	if (hasCycle)
	{
		while (true) {}
		cout << "Not a tree\n";
	}
	else cout << "It's a tree\n";
	//printG();
//	cout << cyclecount;
//	for (auto &i : backedges)
//		PrintCycle(i.second, i.first);
    return 0;
}