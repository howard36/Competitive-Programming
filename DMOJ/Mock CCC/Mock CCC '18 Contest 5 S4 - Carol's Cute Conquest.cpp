#include <cstdio>
int a[1000006];

int main()
{
	int N, K;
	scanf("%d%d", &N, &K);
	for (int i = 0; i < K; i++) {
		scanf("%d", &a[i]);
	}
	long long count = 0;
	int a1 = 0, a2 = 0, a3 = 0;
	for (int i = 0; i < K; i++) {
		count += 1LL * (a[i] - a3 - 1)*a1;
		count += a2;
		a1 = a2;
		a2 = a3;
		a3 = a[i];
	}
	count += 1LL * (N - a[K-1])*a1;
	printf("%lld", count);
    return 0;
}