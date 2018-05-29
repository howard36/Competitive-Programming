#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int q[300005];
vector<int> adj[300005];

long long dfs(int node)
{
	if (adj[node].size() == 0)
		return q[node];
	long long m = 1000000000000000000LL;
	for (int item : adj[node])
		m = min(m, dfs(item));
	m += q[node];
	return m;
}

int main()
{
	int N, M, target, numitems, item;
	scanf("%d%d", &N, &M);
	while (M--)
	{
		scanf("%d%d", &target, &numitems);
		while (numitems--)
		{
			scanf("%d", &item);
			adj[target].push_back(item);
		}
	}
	for (int i = 1; i <= N; i++)
		scanf("%d", &q[i]);
	printf("%lld", dfs(1));
    return 0;
}