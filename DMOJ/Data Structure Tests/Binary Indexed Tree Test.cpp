#include <cstdio>

#define getchar() (*_pinp?*_pinp++:(_inp[fread(_pinp=_inp, 1, 4096, stdin)]='\0', *_pinp++))
char _inp[4097], *_pinp=_inp;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define ll long long

int A[100001];
ll BIT[100001][2];
int n, m;

ll sum(int i, int type)
{
	ll ans = 0;
	while (i >= 1)
	{
		ans += BIT[i][type];
		i -= i&-i;
	}
	return ans;
}

void increment(int i, int inc, int type)
{
	while (i <= 100000)
	{
		BIT[i][type] += inc;
		i += i&-i;
	}
}

ll query(int right, int left)
{
	return sum(left, 0) - sum(right - 1, 0);
}

int main()
{
	scan(n); scan(m);
	int tmp;
	for (int i = 1; i <= n; i++)
	{
		scan(tmp);
		increment(i, tmp, 0);
		increment(tmp, 1, 1);
		A[i] = tmp;
	}
	char t; int a, b;
	while (m--)
	{
		while ((t = getchar())==' ' || t == '\n');
		switch (t)
		{
			case 'C':
				scan(a); scan(b);
				increment(a, b - A[a], 0);
				increment(A[a], -1, 1);
				increment(b, 1, 1);
				A[a] = b;
				break;
			case 'S':
				scan(a); scan(b);
				printf("%lld\n", query(a, b));
				break;
			case 'Q':
				scan(a);
				printf("%lld\n", sum(a, 1));
				break;
		}
	}
	return 0;
}