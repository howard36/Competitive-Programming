#include <cstdio>
#include <algorithm>
#define getchar() (*_pbuf ? *_pbuf++ : (_buf[fread_unlocked(_pbuf = _buf, 1, 16384, stdin)] = 0, *_pbuf++))
char _buf[16385], *_pbuf = _buf;

int read()
{
	int c, o = 0;
	while ((c = getchar()) < '0');
	do o = o * 10 + c - '0';
	while ((c = getchar()) >= '0');
	return o;
}

using namespace std;
const int MAXN = 200000;
const int SQRTN = 450;

int n, q, t, x, v;
int power[MAXN], Next[MAXN], hops[MAXN];

int main()
{
	n = read();
	for (int i = 0; i < n; i++)
		power[i] = read();

	for (int i = n - 1; i >= 0; i--)
	{
		if (i + power[i] >= min((i/SQRTN+1) * SQRTN, n))
		{
			Next[i] = i + power[i];
			hops[i] = 1;
		}
		else
		{
			Next[i] = Next[i + power[i]];
			hops[i] = hops[i + power[i]] + 1;
		}
	}

	q = read();
	for (int j = 0; j < q; j++)
	{
		t = read();
		if (t == 1)
		{
			x = read();
			int count = 0;
			while (x < n)
			{
				count += hops[x];
				x = Next[x];
			}
			printf("%d\n", count);
		}
		else
		{
			x = read(); v = read();
			power[x] = v;
			for (int i = x; i >= x/SQRTN * SQRTN; i--)
			{
				if (i + power[i] >= min((i / SQRTN + 1) * SQRTN, n))
				{
					Next[i] = i + power[i];
					hops[i] = 1;
				}
				else
				{
					Next[i] = Next[i + power[i]];
					hops[i] = hops[i + power[i]] + 1;
				}
			}
		}
	}
    return 0;
}