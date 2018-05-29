#include <cstdio>
#include <vector>
#define ll long long
using namespace std;
const int mod = 1000000007;
int N, start;
int before[200001], after[200001], per[200001], invper[200001], parent[200001], ans[200001];
vector<int> G[200001];

ll BIT[200001];

ll sum(int i)
{
	ll ans = 0;
	for (; i >= 1; i -= i&-i)
		ans = (ans + BIT[i]) % mod;
	return ans;
}

void increment(int i, int inc)
{
	for (; i <= N; i += i&-i)
		BIT[i] = (BIT[i] + inc) % mod;
}

void dfs(int node)
{
	before[node] = sum(invper[node]);
	for (const int &child : G[node])
		dfs(child);
	after[node] = sum(invper[node]);
	ans[node] = (after[node] - before[node] + 1) % mod;
	if (ans[node] < 0) ans[node] += mod;
	increment(invper[node], ans[node]);
}

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &parent[i]);
		G[parent[i]].push_back(i);
		if (parent[i] == 0)
			start = i;
	}
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &per[i]);
		invper[per[i]] = i;
	}
	dfs(start);
	for (int i = 1; i <= N; i++)
		printf("%d ", ans[i]);
    return 0;
}