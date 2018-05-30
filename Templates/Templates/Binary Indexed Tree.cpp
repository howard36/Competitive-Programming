#include "stdafx.h"

using namespace std;
const int max = 100000;
int BIT[max+1]; //1-based indexing

int sum(int i)
{
	int ans = 0;
	for (; i >= 1; i -= i&-i)
		ans += BIT[i];
	return ans;
}

void increment(int i, int inc)
{
	for (; i <= max; i += i&-i)
		BIT[i] += inc;
}

int query(int left, int right)
{
	return sum(right) - sum(left - 1);
}

//2-dimensional BIT
const int maxX = 1000, maxY = 1000;
int BIT2d[maxX + 1][maxY + 1];

int sum2d(int x, int y)
{
	int ans = 0;
	for (int i = x; i >= 1; i -= i&-i)
		for (int j = y; j >= 1; j -= j&-j)
			ans += BIT2d[i][j];
	return ans;
}

void increment2d(int x, int y, int inc)
{
	for (int i = x; i <= maxX; i += i&-i)
		for (int j = y; j <= maxY; j += j&-j)
			BIT2d[i][j] += inc;
}

int query2d(int x1, int y1, int x2, int y2)
{
	return sum2d(x1 - 1, y1 - 1) - sum2d(x1 - 1, y2) - sum2d(x2, y1 - 1) + sum2d(x2, y2);
}