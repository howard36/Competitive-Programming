#include <cstdio>
#include <tuple>
#include <vector>
#include <algorithm>
#define pii pair<int,int>
#define ti5 tuple<int, int, int, int, int> //start, end, height, index, ans
using namespace std;

int BIT[100001];
int N, Q, a, b, q;
vector<pii> heights;
vector<ti5> queries;

inline bool hcomp(pii i, pii j) { return i.second > j.second; }

inline bool qcomp1(ti5 i, ti5 j) { return get<2>(i) > get<2>(j); }

inline bool qcomp2(ti5 i, ti5 j) { return get<3>(i) < get<3>(j); }

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

int query(int right, int left)
{
	return sum(left) - sum(right - 1);
}

int main()
{
	scanf("%d", &N);
	int height;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &height);
		heights.push_back(make_pair(i, height));
	}
	scanf("%d", &Q);
	for (int i = 0; i < Q; i++)
	{
		scanf("%d %d %d", &a, &b, &q);
		queries.push_back(make_tuple(a, b, q, i, 0));
	}
	sort(heights.begin(), heights.end(), hcomp);
	sort(queries.begin(), queries.end(), qcomp1);

	int hpointer = 0;
	for (int qpointer = 0; qpointer < Q; qpointer++)
	{
		while (hpointer < N && heights[hpointer].second >= get<2>(queries[qpointer]))
		{
			increment(heights[hpointer].first + 1, heights[hpointer].second);
			++hpointer;
		}
		get<4>(queries[qpointer]) = query(get<0>(queries[qpointer]) + 1, get<1>(queries[qpointer]) + 1);
	}
	sort(queries.begin(), queries.end(), qcomp2);
	for (int i = 0; i < Q; i++)
		printf("%d\n", get<4>(queries[i]));
	return 0;
}