#include <cstdio>
bool row[1000], col[1000];

int main()
{
	int R, C, Q, x, y; char a;
	scanf("%d %d", &R, &C);
	for (int r = 0; r<R; r++)
	{
		for (int c = 0; c < C; c++)
		{
			scanf(" %c", &a);
			if (a == 'X')
			{
				row[r] = true;
				col[c] = true;
			}
		}
	}
	scanf("%d", &Q);
	while (Q--)
	{
		scanf("%d %d", &x, &y);
		if (col[x-1] || row[y-1])
			printf("Y\n");
		else
			printf("N\n");
	}
    return 0;
}