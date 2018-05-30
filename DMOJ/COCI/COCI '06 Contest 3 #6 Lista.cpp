#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int before[500005];
int after[500005];
int final[500005];
int increasing[500005];
int n, m;

//returns the index of the last value in increasing that does not exceed target
int binarySearch(int left, int right, int target)
{
	while (left < right)
	{
		int mid = (left + right + 1) / 2;
		if (increasing[mid] < target)
			left = mid;
		else if (increasing[mid] > target)
			right = mid - 1;
	}
	return right;
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
	while (m--)
	{
		scanf(" %c %d %d", &t, &x, &y);
		if (t == 'A')
		{
			after[before[x]] = after[x];
			before[after[x]] = before[x];
			after[before[y]] = x;
			before[x] = before[y];
			before[y] = x;
			after[x] = y;
		}
		else
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

	int length = 1;
	for (int i = 1; i <= n; i++)
	{
		int index = binarySearch(0, length-1, final[i]);
		increasing[index + 1] = final[i];
		if (index == length - 1)
			++length;
	}
	
	printf("%d\n", n - length + 1);
	int pointer = 1;
	for (int i = 1; i <= n; i++)
	{
		if (increasing[pointer] != i)
		{
			printf("B %d %d\n", i, i - 1);
		}
		else
			++pointer;
	}

    return 0;
}