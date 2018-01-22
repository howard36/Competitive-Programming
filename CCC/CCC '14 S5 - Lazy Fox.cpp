#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#define pi pair<int,int>
using namespace std;

int points[2001][2];
struct edge { int i, j, d; };
edge edges[2001000];
int dp[2001][3]; //stores max treats, dist of next move, second best treats (with strictly lower distance)
int tmp[3];

bool comp(edge a, edge b) { return a.d < b.d; }

inline int dist(int i, int j) { return (points[i][0] - points[j][0])*(points[i][0] - points[j][0]) + (points[i][1] - points[j][1])*(points[i][1] - points[j][1]); }

int main()
{
	int N, x, y;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d %d", &points[i][0], &points[i][1]);
	int e = 0;
	for (int i = 0; i < N; i++)
		for (int j = i + 1; j <= N; j++)
			edges[e++] = edge{ i,j,dist(i,j) };
	sort(edges, edges + e, comp);

	for (int i = 0; i < e; i++)
	{
		edge ed = edges[i];
		memcpy(tmp, dp[ed.j], sizeof(dp[ed.j]));
		if (ed.i != 0) //consider moving from j to i
		{
			if (ed.d == dp[ed.i][1])
			{
				if (dp[ed.i][2] + 1 > dp[ed.j][0])
				{
					dp[ed.j][2] = dp[ed.j][0];
					dp[ed.j][0] = dp[ed.i][2] + 1;
					dp[ed.j][1] = ed.d;
				}
			}
			else if (dp[ed.i][0] + 1 > dp[ed.j][0])
			{
				dp[ed.j][2] = dp[ed.j][0];
				dp[ed.j][0] = dp[ed.i][0] + 1;
				dp[ed.j][1] = ed.d;
			}
		}

		if (ed.d == tmp[1])
		{
			if (tmp[2] + 1 > dp[ed.i][0])
			{
				dp[ed.i][2] = dp[ed.i][0];
				dp[ed.i][0] = tmp[2] + 1;
				dp[ed.i][1] = ed.d;
			}
		}
		else if (tmp[0] + 1 > dp[ed.i][0])
		{
			dp[ed.i][2] = dp[ed.i][0];
			dp[ed.i][0] = tmp[0] + 1;
			dp[ed.i][1] = ed.d;
		}
	}
	printf("%d", dp[0][0]);
    return 0;
}