#include <cstdio>
#include <cstring>

int unit[200], red[200], irred[200], isprime[200], prime[200];

int gcd(int a, int b)
{
	while (b != 0)
	{
		int t = b;
		b = a % b;
		a = t;
	}
	return a;
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int u = 0; u < n; u++) {
		for (int v = 0; v < n; v++) {
			if ((u*v) % n == 1)	{
				unit[u] = 1;
				unit[v] = 1;
			}
		}
	}
	for (int a = 0; a < n; a++) {
		for (int b = 0; b < n; b++) {
			if (!unit[a] && !unit[b])
				red[(a*b)%n] = 1;
		}
	}
	for (int i = 1; i < n; i++) {
		if (!red[i] && !unit[i])
			irred[i] = 1;
	}
	memset(isprime, 1, sizeof prime);
	for (int i = 2; i < 200; i++) {
		if (isprime[i]) {
			for (int j = i * i; j < 200; j += i)
				isprime[j] = 0;
		}
	}
	for (int p = 1; p < n; p++) {
		if (!unit[p] && isprime[gcd(p, n)])
			prime[p] = 1;
	}
	printf("Units:\n");
	for (int i = 0; i < n; i++)
		if (unit[i])
			printf("%d\n", i);
	printf("Irreducibles:\n");
	for (int i = 0; i < n; i++)
		if (irred[i])
			printf("%d\n", i);
	printf("Primes:\n");
	for (int i = 0; i < n; i++)
		if (prime[i])
			printf("%d\n", i);
    return 0;
}