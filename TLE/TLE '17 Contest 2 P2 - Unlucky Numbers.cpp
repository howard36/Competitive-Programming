#include <cstdio>

int real[1000006], unlucky[1000006];

int main()
{
	int N, K, f, u;
	scanf("%d", &K);
	for (int i = 0; i < K; i++)
	{
		scanf("%d", &u);
		unlucky[u] = 1;
	}
	for (int i = 1; i <= 1000000; i++)
	{
		if (unlucky[i])
			real[i] = real[i - 1];
		else
			real[i] = real[i - 1] + 1;
	}

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &f);
		printf("%d\n", real[f]);
	}
    return 0;
}