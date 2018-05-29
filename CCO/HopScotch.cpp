#include <cstdio>
#define max(a,b) (a>b)?a:b
using namespace std;
const int MAXN = 200000;
const int SQRTN = 450;

int n, q, t, x, v;
int power[MAXN], next[MAXN], hops[MAXN];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &power[i]);

	for (int i = n - 1; i >= 0; i--)
	{
		if (i + power[i] >= max((i/SQRTN+1) * SQRTN, n))
		{
			next[i] = i + power[i];
			hops[i] = 1;
		}
		else
		{
			next[i] = next[i + power[i]];
			hops[i] = hops[i + power[i]] + 1;
		}
	}

	scanf("%d", &q);
	for (int j = 0; j < q; j++)
	{
		scanf("%d", &t);
		if (t == 1)
		{
			scanf("%d", &x);
			int count = 0;
			while (x < n)
			{
				count += hops[x];
				x = next[x];
			}
			printf("%d", count);
		}
		else
		{
			scanf("%d %d", &x, &v);
			power[x] = v;
			for (int i = x; i >= x/SQRTN * SQRTN; i--)
			{
				if (i + power[i] >= max((i / SQRTN + 1) * SQRTN, n))
				{
					next[i] = i + power[i];
					hops[i] = 1;
				}
				else
				{
					next[i] = next[i + power[i]];
					hops[i] = hops[i + power[i]] + 1;
				}
			}
		}
	}
    return 0;
}