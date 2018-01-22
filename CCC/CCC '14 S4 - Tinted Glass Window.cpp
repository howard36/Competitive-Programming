#include <cstdio>
#include <map>
using namespace std;

int glass[1000][5];
int n, t;
map<int,int> allX, allY;
int realX[2002], realY[2002];
int grid[2002][2002];

int main()
{
	scanf("%d %d", &n, &t);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d %d %d %d", &glass[i][0], &glass[i][1], &glass[i][2], &glass[i][3], &glass[i][4]);
		allX[glass[i][0]] = 0;
		allX[glass[i][2]] = 0;
		allY[glass[i][1]] = 0;
		allY[glass[i][3]] = 0;
	}
	int xcount = 1, ycount = 1;
	for (const auto &pair : allX)
	{
		allX[pair.first] = xcount;
		realX[xcount] = pair.first;
		++xcount;
	}
	for (const auto &pair : allY)
	{
		allY[pair.first] = ycount;
		realY[ycount] = pair.first;
		++ycount;
	}

	for (int i = 0; i < n; i++)
	{
		grid[allX[glass[i][0]]][allY[glass[i][1]]] += glass[i][4];
		grid[allX[glass[i][2]]][allY[glass[i][1]]] -= glass[i][4];
		grid[allX[glass[i][0]]][allY[glass[i][3]]] -= glass[i][4];
		grid[allX[glass[i][2]]][allY[glass[i][3]]] += glass[i][4];
	}

	unsigned long long area = 0ULL;
	for (int i = 1; i <= xcount; i++)
	{
		for (int j = 1; j <= ycount; j++)
		{
			grid[i][j] += grid[i][j - 1] + grid[i - 1][j] - grid[i - 1][j - 1];
			if (grid[i][j] >= t)
				area += (1LL*realX[i + 1] - realX[i])*(realY[j + 1] - realY[j]);
		}
	}
	printf("%llu", area);
    return 0;
}