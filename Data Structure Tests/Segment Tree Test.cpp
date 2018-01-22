#include <vector>
#include <algorithm>
#include <tuple>
#define ti3 tuple<int,int,int>
#define mt make_tuple
using namespace std;

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

int A[100010];
vector<ti3> SegmentTree(300000);

//type: 0 = index of minimum in range, 1 = index of maximum in range, 2 = sum of range
//b = beginning, e = end (inclusive)
void BuildSegmentTree(int node, int b, int e)
{
	if (b == e)
		SegmentTree[node] = make_tuple(A[b], A[b], 1);
	else
	{
		int lIndex = 2 * node, rIndex = 2 * node + 1;
		BuildSegmentTree(lIndex, b, (b + e) / 2);
		BuildSegmentTree(rIndex, (b + e) / 2 + 1, e);

		ti3 lContent = SegmentTree[lIndex], rContent = SegmentTree[rIndex];
		SegmentTree[node] = mt(min(get<0>(lContent), get<0>(rContent)), gcd(get<1>(lContent), get<1>(rContent)), 0);
		if (get<1>(lContent) == get<1>(SegmentTree[node]))
			get<2>(SegmentTree[node]) += get<2>(lContent);
		if (get<1>(rContent) == get<1>(SegmentTree[node]))
			get<2>(SegmentTree[node]) += get<2>(rContent);
	}
}

//i = start of query range, j = end of query range (inclusive)
ti3 SegmentTreeQuery(int node, int b, int e, int i, int j)
{
	if (i > e || j < b)	return mt(-1, 0, 0);	// interval does not intersect query interval
	if (b >= i && e <= j)						// interval is inside query interval
	{
		return SegmentTree[node];
	}

	ti3 p1 = SegmentTreeQuery(2 * node, b, (b + e) / 2, i, j);
	ti3 p2 = SegmentTreeQuery(2 * node + 1, (b + e) / 2 + 1, e, i, j);

	if (get<0>(p1) == -1) return p2; // in case we try to access segment outside query
	if (get<0>(p2) == -1) return p1;

	int _min = min(get<0>(p1), get<0>(p2));
	int _gcd = gcd(get<1>(p1), get<1>(p2));
	int numgcd = 0;
	if (get<1>(p1) == _gcd)
		numgcd += get<2>(p1);
	if (get<1>(p2) == _gcd)
		numgcd += get<2>(p2);

	return mt(_min, _gcd, numgcd);
}

//does not update array itself
void UpdateSegmentTree(int node, int b, int e, int index, int value)
{
	if (b>index || e<index) return;
	if (b == e)
	{
		SegmentTree[node] = mt(value, value, 1);
		return;
	}

	int lIndex = 2 * node, rIndex = 2 * node + 1;
	UpdateSegmentTree(lIndex, b, (b + e) / 2, index, value);
	UpdateSegmentTree(rIndex, (b + e) / 2 + 1, e, index, value);

	ti3 lContent = SegmentTree[lIndex], rContent = SegmentTree[rIndex];
	SegmentTree[node] = mt(min(get<0>(lContent), get<0>(rContent)), gcd(get<1>(lContent), get<1>(rContent)), 0);
	if (get<1>(lContent) == get<1>(SegmentTree[node]))
		get<2>(SegmentTree[node]) += get<2>(lContent);
	if (get<1>(rContent) == get<1>(SegmentTree[node]))
		get<2>(SegmentTree[node]) += get<2>(rContent);
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &A[i]);
	BuildSegmentTree(1, 1, n);

	char c; int a, b;
	for (int i = 0; i < m; i++)
	{
		scanf(" %c %d %d", &c, &a, &b);
		switch (c)
		{
			case 'C':
				UpdateSegmentTree(1, 1, n, a, b);
				break;
			case 'M':
				printf("%d\n", get<0>(SegmentTreeQuery(1, 1, n, a, b)));
				break;
			case 'G':
				printf("%d\n", get<1>(SegmentTreeQuery(1, 1, n, a, b)));
				break;
			case 'Q':
				printf("%d\n", get<2>(SegmentTreeQuery(1, 1, n, a, b)));
				break;
		}
	}
    return 0;
}