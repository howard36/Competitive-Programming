#include <cstdio>
#include <cstring>

int prime[100005];

int main()
{
	memset(prime, 1, sizeof(prime));
	prime[1] = 0;
	for (int i = 2; i < 100005; ++i)
	{
		if (prime[i])
		{
			for (int j = 2 * i; j < 100005; j += i)
				prime[j] = 0;
		}
	}
	int n, f, count = 0;
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &f);
		if (prime[f])
			++count;
	}
	printf("%d", count);
    return 0;
}