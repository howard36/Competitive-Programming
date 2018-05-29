#include <vector>
#include <cstdio>
#include <algorithm>
#define pii pair<int,int>
using namespace std;
vector<pii> blocks;

inline bool comp(pii i, pii j)
{
	return (i.second == j.second) ? (i.first < j.first) : (i.second < j.second);
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	int r, c;
	while (m--)
	{
		scanf("%d %d", &r, &c);
		blocks.push_back(make_pair(r, c));
	}
	sort(blocks.begin(), blocks.end(), comp);
	pii cur = blocks[0];
	long long sum = 0;
	for (pii &block : blocks)
	{
		if (block.first - block.second < cur.first - cur.second)
		{
			long long h = n - cur.first + 1;
			long long smallh = max(0LL, h - (block.second - cur.second));
			sum += h*(h + 1) / 2 - smallh*(smallh + 1) / 2;
			cur = block;
		}
	}
	long long h = n - cur.first + 1;
	sum += h*(h + 1) / 2;
	printf("%lld", sum);
    return 0;
}