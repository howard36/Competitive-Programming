#include <cstdio>
const int mod = 1000000007;

int degree[200005];

int main()
{
	int N, x;
	long long count = 1;
	scanf("%d", &N);
	for (int i = 1; i < N; i++) {
		scanf("%d", &x);
		degree[x]++;
		count = count * (degree[x] + 1) % mod;
	}
	printf("%lld", count);
    return 0;
}