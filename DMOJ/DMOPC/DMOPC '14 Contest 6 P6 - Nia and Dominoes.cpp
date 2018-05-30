#include <cstdio>
#define getchar getchar_unlocked

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
	int A, B, M;
	scanf("%d %d %d", &A, &B, &M);
	int d = gcd(A, B);
	if (d == 0)
	{
	    printf("0");
	    return 0;
	}
	int m = M, exp = 0; //M = m*d^exp
	if (d != 1)
		while (m%d == 0)
		{
			m /= d;
			exp++;
		}
		
	int start1 = 1, start2 = A%m, t;
	for (int i = 0; i < M/100; i++)
	{
		t = start2;
		start2 = (A*start2 + B*start1) % m;
		start1 = t;
	}
	
	int x = start1, y = start2, period = 0;
	do
	{
		t = y;
		y = (A*y + B*x) % m;
		x = t;
		period++;
	} while (x != start1 || y != start2);
	
	int n;
	char digit;
	while ((n = getchar()) < '0');
	n -= '0';
	while ('0' <= (digit = getchar()))
	{
		n = (n << 3) + (n << 1) + (digit&15);
		if (period != 1) n %= period;
	}
	
	x = 1, y = A;
	for (int i = 0; i < n; i++)
	{
		t = y;
		y = (A*y + B*x) % M;
		x = t;
	}
	printf("%d", x);
	return 0;
}