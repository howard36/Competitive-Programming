#include <cstdio>
#define ll long long

int main()
{
	ll N;
	scanf("%lld", &N);
	int max;
	for (int i = 0; i < 64; i++) {
		if (N & (1LL << i))
			max = i + 1;
	}
	printf("%d\n", max);
	for (int i = 0; i < max - 1; i++)
		printf("%lld ", 1LL << i);
	printf("%lld", N - (1LL << (max-1)) + 1);

    return 0;
}