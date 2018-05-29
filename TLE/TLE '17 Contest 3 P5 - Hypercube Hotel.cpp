#include <cstdio>
#include <cstring>
#define ull unsigned long long

#define getchar() (*_pbuf ? *_pbuf++ : (_buf[fread_unlocked(_pbuf = _buf, 1, 1048576, stdin)] = 0, *_pbuf++))
char _buf[1048577], *_pbuf = _buf;
ull read() {
	int c; ull o = 0;
	while ((c = getchar()) < '0');
	do o = (o<<3)+(o<<1) + (c - '0'); while ((c = getchar()) >= '0');
	return o;
}

int s[9], N, p[10];
ull a[3][5][5][5][5][5][5][5][5][5];

inline int c(int n, int i)
{
	return (n / p[i + 1]) % s[i];
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &s[i]);
	for (int i = N; i < 9; i++)
		s[i] = 1;
	p[9] = 1;
	for (int i = 8; i >= 0; i--)
		p[i] = p[i + 1] * s[i];
	for (int n = 0; n < p[0]; n++)
	{
		a[0][c(n, 0)][c(n, 1)][c(n, 2)][c(n, 3)][c(n, 4)][c(n, 5)][c(n, 6)][c(n, 7)][c(n, 8)]=read();
		a[2][c(n, 0)][c(n, 1)][c(n, 2)][c(n, 3)][c(n, 4)][c(n, 5)][c(n, 6)][c(n, 7)][c(n, 8)] = a[0][c(n, 0)][c(n, 1)][c(n, 2)][c(n, 3)][c(n, 4)][c(n, 5)][c(n, 6)][c(n, 7)][c(n, 8)];
	}

	for (int n = 0; n < p[0]; n++)
	{
		ull x = a[0][c(n, 0)][c(n, 1)][c(n, 2)][c(n, 3)][c(n, 4)][c(n, 5)][c(n, 6)][c(n, 7)][c(n, 8)];
		if (c(n, 0) > 0)
			a[1][c(n, 0) - 1][c(n, 1)][c(n, 2)][c(n, 3)][c(n, 4)][c(n, 5)][c(n, 6)][c(n, 7)][c(n, 8)] += x;
		a[1][c(n, 0)][c(n, 1)][c(n, 2)][c(n, 3)][c(n, 4)][c(n, 5)][c(n, 6)][c(n, 7)][c(n, 8)] += x;
		if (c(n, 0) < s[0] - 1)
			a[1][c(n, 0) + 1][c(n, 1)][c(n, 2)][c(n, 3)][c(n, 4)][c(n, 5)][c(n, 6)][c(n, 7)][c(n, 8)] += x;
	}
	memset(a[0], 0, sizeof(a[0]));
	for (int n = 0; n < p[0]; n++)
	{
		ull x = a[1][c(n, 0)][c(n, 1)][c(n, 2)][c(n, 3)][c(n, 4)][c(n, 5)][c(n, 6)][c(n, 7)][c(n, 8)];
		if (c(n, 1) > 0)
			a[0][c(n, 0)][c(n, 1)-1][c(n, 2)][c(n, 3)][c(n, 4)][c(n, 5)][c(n, 6)][c(n, 7)][c(n, 8)] += x;
		a[0][c(n, 0)][c(n, 1)][c(n, 2)][c(n, 3)][c(n, 4)][c(n, 5)][c(n, 6)][c(n, 7)][c(n, 8)] += x;
		if (c(n, 1) < s[1] - 1)
			a[0][c(n, 0)][c(n, 1)+1][c(n, 2)][c(n, 3)][c(n, 4)][c(n, 5)][c(n, 6)][c(n, 7)][c(n, 8)] += x;
	}
	memset(a[1], 0, sizeof(a[1]));
	for (int n = 0; n < p[0]; n++)
	{
		ull x = a[0][c(n, 0)][c(n, 1)][c(n, 2)][c(n, 3)][c(n, 4)][c(n, 5)][c(n, 6)][c(n, 7)][c(n, 8)];
		if (c(n, 2) > 0)
			a[1][c(n, 0)][c(n, 1)][c(n, 2)-1][c(n, 3)][c(n, 4)][c(n, 5)][c(n, 6)][c(n, 7)][c(n, 8)] += x;
		a[1][c(n, 0)][c(n, 1)][c(n, 2)][c(n, 3)][c(n, 4)][c(n, 5)][c(n, 6)][c(n, 7)][c(n, 8)] += x;
		if (c(n, 2) < s[2] - 1)
			a[1][c(n, 0)][c(n, 1)][c(n, 2)+1][c(n, 3)][c(n, 4)][c(n, 5)][c(n, 6)][c(n, 7)][c(n, 8)] += x;
	}
	memset(a[0], 0, sizeof(a[0]));
	for (int n = 0; n < p[0]; n++)
	{
		ull x = a[1][c(n, 0)][c(n, 1)][c(n, 2)][c(n, 3)][c(n, 4)][c(n, 5)][c(n, 6)][c(n, 7)][c(n, 8)];
		if (c(n, 3) > 0)
			a[0][c(n, 0)][c(n, 1)][c(n, 2)][c(n, 3)-1][c(n, 4)][c(n, 5)][c(n, 6)][c(n, 7)][c(n, 8)] += x;
		a[0][c(n, 0)][c(n, 1)][c(n, 2)][c(n, 3)][c(n, 4)][c(n, 5)][c(n, 6)][c(n, 7)][c(n, 8)] += x;
		if (c(n, 3) < s[3] - 1)
			a[0][c(n, 0)][c(n, 1)][c(n, 2)][c(n, 3)+1][c(n, 4)][c(n, 5)][c(n, 6)][c(n, 7)][c(n, 8)] += x;
	}
	memset(a[1], 0, sizeof(a[1]));
	for (int n = 0; n < p[0]; n++)
	{
		ull x = a[0][c(n, 0)][c(n, 1)][c(n, 2)][c(n, 3)][c(n, 4)][c(n, 5)][c(n, 6)][c(n, 7)][c(n, 8)];
		if (c(n, 4) > 0)
			a[1][c(n, 0)][c(n, 1)][c(n, 2)][c(n, 3)][c(n, 4)-1][c(n, 5)][c(n, 6)][c(n, 7)][c(n, 8)] += x;
		a[1][c(n, 0)][c(n, 1)][c(n, 2)][c(n, 3)][c(n, 4)][c(n, 5)][c(n, 6)][c(n, 7)][c(n, 8)] += x;
		if (c(n, 4) < s[4] - 1)
			a[1][c(n, 0)][c(n, 1)][c(n, 2)][c(n, 3)][c(n, 4)+1][c(n, 5)][c(n, 6)][c(n, 7)][c(n, 8)] += x;
	}
	memset(a[0], 0, sizeof(a[0]));
	for (int n = 0; n < p[0]; n++)
	{
		ull x = a[1][c(n, 0)][c(n, 1)][c(n, 2)][c(n, 3)][c(n, 4)][c(n, 5)][c(n, 6)][c(n, 7)][c(n, 8)];
		if (c(n, 5) > 0)
			a[0][c(n, 0)][c(n, 1)][c(n, 2)][c(n, 3)][c(n, 4)][c(n, 5)-1][c(n, 6)][c(n, 7)][c(n, 8)] += x;
		a[0][c(n, 0)][c(n, 1)][c(n, 2)][c(n, 3)][c(n, 4)][c(n, 5)][c(n, 6)][c(n, 7)][c(n, 8)] += x;
		if (c(n, 5) < s[5] - 1)
			a[0][c(n, 0)][c(n, 1)][c(n, 2)][c(n, 3)][c(n, 4)][c(n, 5)+1][c(n, 6)][c(n, 7)][c(n, 8)] += x;
	}
	memset(a[1], 0, sizeof(a[1]));
	for (int n = 0; n < p[0]; n++)
	{
		ull x = a[0][c(n, 0)][c(n, 1)][c(n, 2)][c(n, 3)][c(n, 4)][c(n, 5)][c(n, 6)][c(n, 7)][c(n, 8)];
		if (c(n, 6) > 0)
			a[1][c(n, 0)][c(n, 1)][c(n, 2)][c(n, 3)][c(n, 4)][c(n, 5)][c(n, 6)-1][c(n, 7)][c(n, 8)] += x;
		a[1][c(n, 0)][c(n, 1)][c(n, 2)][c(n, 3)][c(n, 4)][c(n, 5)][c(n, 6)][c(n, 7)][c(n, 8)] += x;
		if (c(n, 6) < s[6] - 1)
			a[1][c(n, 0)][c(n, 1)][c(n, 2)][c(n, 3)][c(n, 4)][c(n, 5)][c(n, 6)+1][c(n, 7)][c(n, 8)] += x;
	}
	memset(a[0], 0, sizeof(a[0]));
	for (int n = 0; n < p[0]; n++)
	{
		ull x = a[1][c(n, 0)][c(n, 1)][c(n, 2)][c(n, 3)][c(n, 4)][c(n, 5)][c(n, 6)][c(n, 7)][c(n, 8)];
		if (c(n, 7) > 0)
			a[0][c(n, 0)][c(n, 1)][c(n, 2)][c(n, 3)][c(n, 4)][c(n, 5)][c(n, 6)][c(n, 7)-1][c(n, 8)] += x;
		a[0][c(n, 0)][c(n, 1)][c(n, 2)][c(n, 3)][c(n, 4)][c(n, 5)][c(n, 6)][c(n, 7)][c(n, 8)] += x;
		if (c(n, 7) < s[7] - 1)
			a[0][c(n, 0)][c(n, 1)][c(n, 2)][c(n, 3)][c(n, 4)][c(n, 5)][c(n, 6)][c(n, 7)+1][c(n, 8)] += x;
	}
	memset(a[1], 0, sizeof(a[1]));
	for (int n = 0; n < p[0]; n++)
	{
		ull x = a[0][c(n, 0)][c(n, 1)][c(n, 2)][c(n, 3)][c(n, 4)][c(n, 5)][c(n, 6)][c(n, 7)][c(n, 8)];
		if (c(n, 8) > 0)
			a[1][c(n, 0)][c(n, 1)][c(n, 2)][c(n, 3)][c(n, 4)][c(n, 5)][c(n, 6)][c(n, 7)][c(n, 8)-1] += x;
		a[1][c(n, 0)][c(n, 1)][c(n, 2)][c(n, 3)][c(n, 4)][c(n, 5)][c(n, 6)][c(n, 7)][c(n, 8)] += x;
		if (c(n, 8) < s[8] - 1)
			a[1][c(n, 0)][c(n, 1)][c(n, 2)][c(n, 3)][c(n, 4)][c(n, 5)][c(n, 6)][c(n, 7)][c(n, 8)+1] += x;
	}

	for (int n = 0; n < p[0]; n++)
	{
		printf("%llu\n", a[1][c(n, 0)][c(n, 1)][c(n, 2)][c(n, 3)][c(n, 4)][c(n, 5)][c(n, 6)][c(n, 7)][c(n, 8)] - a[2][c(n, 0)][c(n, 1)][c(n, 2)][c(n, 3)][c(n, 4)][c(n, 5)][c(n, 6)][c(n, 7)][c(n, 8)]);
	}

	
    return 0;
}