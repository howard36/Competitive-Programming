#include <vector>
#include <cstdio>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

long long BIT3d[251][251][251];
int arr[251][251][251];

int N, Q;

long long sum3d(int x, int y, int z)
{
	long long ans = 0;
	while (x >= 1)
	{
		int tmp1 = y;
		while (tmp1 >= 1)
		{
			int tmp2 = z;
			while (tmp2 >= 1)
			{
				ans += BIT3d[x][tmp1][tmp2];
				tmp2 -= tmp2&-tmp2;
			}
			tmp1 -= tmp1&-tmp1;
		}
		x -= x&-x;
	}
	return ans;
}

void increment3d(int x, int y, int z, int inc)
{
	while (x <= N)
	{
		int tmp1 = y;
		while (tmp1 <= N)
		{
			int tmp2 = z;
			while (tmp2 <= N)
			{
				BIT3d[x][tmp1][tmp2] += inc;
				tmp2 += tmp2&-tmp2;
			}
			tmp1 += tmp1&-tmp1;
		}
		x += x&-x;
	}
}

long long query3d(int x1, int y1, int z1, int x2, int y2, int z2)
{
	return sum3d(x2, y2, z2) - sum3d(x2, y2, z1 - 1) - sum3d(x2, y1 - 1, z2) - sum3d(x1 - 1, y2, z2) + sum3d(x2, y1 - 1, z1 - 1) + sum3d(x1 - 1, y2, z1 - 1) + sum3d(x1 - 1, y1 - 1, z2) - sum3d(x1 - 1, y1 - 1, z1 - 1);
}

int main()
{
	scan(N); scan(Q);
	char type;
	long long ans = 0;
	while (Q--)
	{
		scanf(" %c", &type);
		if (type == 'C')
		{
			int x, y, z, l;
			scan(x); scan(y); scan(z); scan(l);
			increment3d(x, y, z, l - arr[x][y][z]);
			arr[x][y][z] = l;
		}
		else
		{
			int x1, y1, z1, x2, y2, z2;
			scan(x1); scan(y1); scan(z1); scan(x2); scan(y2); scan(z2);
			ans += query3d(x1, y1, z1, x2, y2, z2);
		}
	}
	printf("%lld", ans);
	return 0;
}