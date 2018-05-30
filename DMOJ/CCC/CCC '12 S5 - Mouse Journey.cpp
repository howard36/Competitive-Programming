#include <cstdio>

int arr[26][26];

int main()
{
	int R, C, K, x, y;
	scanf("%d %d %d", &R, &C, &K);
	while (K--)
	{
		scanf("%d %d", &x, &y);
		arr[x][y] = -1;
	}
	arr[1][1] = 1;
	for (int r=1; r<=R; r++)
		for (int c = 1; c <= C; c++)
		{
			if (arr[r][c] == -1) continue;
			if (arr[r][c - 1] != -1) arr[r][c] += arr[r][c - 1];
			if (arr[r - 1][c] != -1) arr[r][c] += arr[r - 1][c];
		}
	printf("%d", arr[R][C]);
    return 0;
}