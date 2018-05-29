#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>
#include <tuple>
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