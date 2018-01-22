#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>
#include <tuple>
#define vi vector<int>
#define ti4 tuple<int,int,int,int>
#define pi pair<int,int>
#define mt make_tuple
#define mp make_pair
using namespace std;

int BIT[1000001];
int h[1000001];
stack<pi> peaks;
int N, Q;
vector<ti4> queries;

int sum(int i)
{
	int ans = 0;
	for (; i >= 1; i -= i&-i)
		ans += BIT[i];
	return ans;
}

void increment(int i, int inc)
{
	for (; i <= N; i += i&-i)
		BIT[i] += inc;
}
/*
vi sparse[10000][5];

vi merge(vi &a, vi &b)
{
	auto it = upper_bound(b.begin(), b.end(), a.back());
	vi ret = a;
	ret.insert(ret.end(), it, b.end());
	return ret;
}

int solve(int l, int r)
{
	int diff = r - l + 1, k = 0;
	while (diff > 1)
	{
		diff >>= 1;
		++k;
	}
	vi ans = sparse[l][k];
	l += 1 << k;
	--k;
	while (l <= r)
	{
		if (l + (1 << k) <= r)
		{
			ans = merge(ans, sparse[l][k]);
			l += 1 << k;
		}
		--k;
	}
//	for (int i : ans) printf("%d", i);
	return ans.size();
}
*/
bool comp1(ti4 x, ti4 y)
{
	return get<0>(x) > get<0>(y);
}

bool comp2(ti4 x, ti4 y)
{
	return get<3>(x) < get<3>(y);
}

int main()
{
	scanf("%d %d", &N, &Q);
	for (int i = 1; i <= N; i++)
		scanf("%d", &h[i]);
	/*
	for (int i = 1; i <= N; i++)
		sparse[i][0] = { h[i] };
	for (int j = 1; 1 << j <= N; j++)
		for (int i = 1; i <= N - (1 << j) + 1; i++)
		{
			sparse[i][j] = merge(sparse[i][j - 1], sparse[i + (1 << (j - 1))][j - 1]);
//			printf("sparse[%d][%d] = ", i, j);
//			for (int k : sparse[i][j]) printf("%d ", k);
//			printf("\n");
		}*/
	
	int l, r;
	for (int i = 0; i < Q; i++)
	{
		scanf("%d %d", &l, &r);
		queries.push_back(mt(l, r, 0, i));
	}
	sort(queries.begin(), queries.end(), comp1);

	int q = 0;
	for (int pos = N; pos > 0; pos--)
	{
		while (!peaks.empty() && h[pos] > peaks.top().first)
		{
			increment(peaks.top().second, -1);
			peaks.pop();
		}
		peaks.push(mp(h[pos], pos));
		increment(pos, 1);
		while (q < Q && get<0>(queries[q]) == pos)
		{
			get<2>(queries[q]) = sum(get<1>(queries[q]));
			++q;
		}
	}

	sort(queries.begin(), queries.end(), comp2);
	for (auto query : queries)
		printf("%d\n", get<2>(query));
    return 0;
}