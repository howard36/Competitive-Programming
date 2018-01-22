#include <cstdio>
#include <deque>
#include <algorithm>
#define pi pair<int,int>
#define mp make_pair
using namespace std;

int a[100005], Llength[100005], Rlength[100005];
deque<pi> Min, Max;
int sparse[100005][17];

int query(int l, int r)
{
	int d = r - l + 1, k = 0;
	while (1 << k <= d) k++;
	k--;
	if (Llength[sparse[l][k]] >= Llength[sparse[r - (1 << k) + 1][k]])
		return sparse[l][k];
	else
		return sparse[r - (1 << k) + 1][k];
}

int main()
{
	int N, K, Q;
	scanf("%d%d", &N, &K);
	for (int i = 1; i <= N; i++)
		scanf("%d", &a[i]);

	Max.push_back(mp(a[1], 1)); Min.push_back(mp(a[1], 1));
	int start = 1, end = 1;
	Rlength[1] = 1;
	while (end != N)
	{
		while (Max.front().first - Min.front().first <= K && end <= N-1)
		{
			++end;
			while (!Max.empty() && a[end] >= Max.back().first) Max.pop_back();
			Max.push_back(mp(a[end], end));
			while (!Min.empty() && a[end] <= Min.back().first) Min.pop_back();
			Min.push_back(mp(a[end], end));
			if (Max.front().first - Min.front().first <= K)
				Rlength[end] = end - start + 1;
		}
		while (Max.front().first - Min.front().first > K)
		{
			int next = min(Max.front().second, Min.front().second) + 1;
			while (start < next)
			{
				Llength[start] = end - start;
				++start;
			}
			while (Max.front().second < start) Max.pop_front();
			while (Min.front().second < start) Min.pop_front();
		}
		Rlength[end] = end - start + 1;
	}
	while (start < end)
	{
		Llength[start] = end - start + 1;
		++start;
	}

	for (int i = 1; i <= N; i++)
		sparse[i][0] = i;
	for (int j = 1; j < 17; j++)
		for (int i = 1; i + (1 << j) - 1 <= N; i++)
		{
			if (Llength[sparse[i][j - 1]] >= Llength[sparse[i + (1 << (j - 1))][j - 1]])
				sparse[i][j] = sparse[i][j - 1];
			else
				sparse[i][j] = sparse[i + (1 << (j - 1))][j - 1];
		}

	scanf("%d", &Q);
	int l, r;
	while (Q--)
	{
		scanf("%d%d", &l, &r);
		if (r - Rlength[r] < l)
		{
			printf("%d %d\n", l, r);
			continue;
		}

		int idx = query(l, r - Rlength[r]);
		if (Llength[idx] >= Rlength[r])
			printf("%d %d\n", idx, idx + Llength[idx] - 1);
		else
			printf("%d %d\n", r - Rlength[r] + 1, r);
	}

    return 0;
}