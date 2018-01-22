#include <cstdio>

int arr[200000];

int fastPow(int b, int exp) {
	int ans = 1, pow = b;
	while (exp > 0)	{
		if (exp & 1)
			ans *= pow;
		exp >>= 1;
		pow = pow * pow;
	}
	return ans;
}

int main()
{
	int P, Q, N, X;
	scanf("%d%d%d", &P, &Q, &N);
	for (int i = 0; i < N; i++)	{
		int a = 0, b;
		for (int j = 0; j < P; j++)	{
			scanf("%d", &b);
			a = a*Q + b;
		}
		arr[a] += 1;
	}

	int max = fastPow(Q, P);
	int diff = 1;
	for (int i = 0; i < P; i++) {
		for (int j = max - 1; j >= 0; j--)
		{
			if ((j/diff) % Q != 0)
				arr[j - diff] += arr[j];
		}
		diff *= Q;
	}

	scanf("%d", &X);
	for (int i = 0; i < X; i++) {
		int a = 0, b;
		for (int j = 0; j < P; j++)	{
			scanf("%d", &b);
			a = a*Q + b;
		}
		printf("%d\n", arr[a]);
	}
    return 0;
}