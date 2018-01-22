#include <cstdio>
int a[100001];

int main()
{
	int n, t, vcount = 0, change;
	scanf("%d %d", &n, &t);
	char c;
	for (int i = 1; i <= n; i++)
	{
		scanf(" %c", &c);
		if (c == '|')
		{
			++vcount;
			a[i] = 1;
		}
		else
			a[i] = 0;
	}
	for (int i = 0; i < t; i++)
	{
		scanf("%d", &change);
		if (a[change] == 0)
		{
			a[change] = 1;
			++vcount;
		}
		else
		{
			a[change] = 0;
			--vcount;
		}
		if (a[1] == 1)
			printf("1\n");
		else
			printf("%d\n", n + 2 * vcount);
	}
    return 0;
}