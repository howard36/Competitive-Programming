#include <cstdio>
int main()
{
	int n, min, a;
	scanf("%d, %d", &n, &min);
	for (int i = 1; i < n; i++)
	{
		scanf("%d", &a);
		if (a < min)
			min = a;
	}
	printf("%d", min);
    return 0;
}