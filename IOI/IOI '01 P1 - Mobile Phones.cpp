#include <vector>
#include <cstdio>
using namespace std;
vector<vector<int> > BIT2d(1100, vector<int>(1100));

int S, type, x, y, a, l, b, r, t;

int sum2d(int i, int j)
{
	int ans = 0;
	while (i >= 1)
	{
		int tmp = j;
		while (tmp >= 1)
		{
			ans += BIT2d[i][tmp];
			tmp -= tmp&-tmp;
		}
		i -= i&-i;
	}
	return ans;
}

void increment2d(int i, int j, int inc)
{
	while (i <= S)
	{
		int tmp = j;
		while (tmp <= S)
		{
			BIT2d[i][tmp] += inc;
			tmp += tmp&-tmp;
		}
		i += i&-i;
	}
}

int query2d(int i1, int j1, int i2, int j2)
{
	return sum2d(i1 - 1, j1 - 1) - sum2d(i1 - 1, j2) - sum2d(i2, j1 - 1) + sum2d(i2, j2);
}

int main()
{
	scanf("%d %d", &type, &S);
	while (true)
	{
		scanf("%d", &type);
		if (type == 1)
		{
			scanf("%d %d %d", &x, &y, &a);
			increment2d(x + 1, y + 1, a);
		}
		else if (type == 2)
		{
			scanf("%d %d %d %d", &l, &b, &r, &t);
			printf("%d\n", query2d(l + 1, b + 1, r + 1, t + 1));
		}
		else break;
	}
    return 0;
}