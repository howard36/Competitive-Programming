#include <cstdio>
#include <algorithm>
using namespace std;

int before[500001];
int after[500001];
int final[500001];
int increasing[500001];
int idxlast[500001];
int pre[500001];
int n, m;

int binarySearch(int left, int right, int target)
{
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (final[idxlast[mid]] < target)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return left - 1;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		before[i] = i - 1;
	before[0] = n;
	for (int i = 0; i < n; i++)
		after[i] = i + 1;
	after[n] = 0;

	char t; int x, y;
	for (int i = 0; i < m; i++)
	{
		scanf(" %c %d %d", &t, &x, &y);
		if (t == 'A' && x != before[y])
		{
			after[before[x]] = after[x];
			before[after[x]] = before[x];
			after[before[y]] = x;
			before[x] = before[y];
			before[y] = x;
			after[x] = y;
		}
		else if (t == 'B' && x != after[y])
		{
			after[before[x]] = after[x];
			before[after[x]] = before[x];
			before[after[y]] = x;
			after[x] = after[y];
			after[y] = x;
			before[x] = y;
		}
	}

	for (int i = 1; i <= n; i++)
		final[i] = after[final[i - 1]];

	int length = 0;
	for (int i = 1; i <= n; i++)
	{
		int index = binarySearch(1, length, final[i]);
		pre[i] = idxlast[index];
		idxlast[index + 1] = i;
		length = max(length, index + 1);
	}
	int k = idxlast[length];
	for (int i = length - 1; i >= 0; i--)
	{
		increasing[i] = final[k];
		k = pre[k];
	}

	printf("%d\n", n - length);
	int pointer = 0;
	for (int i = increasing[0]; i <= n; i++)
	{
		if (increasing[pointer] != i)
			printf("B %d %d\n", i, i - 1);
		else
			++pointer;
	}
	for (int i = increasing[0] - 1; i >= 1; i--)
		printf("A %d %d\n", i, i + 1);
    return 0;
}