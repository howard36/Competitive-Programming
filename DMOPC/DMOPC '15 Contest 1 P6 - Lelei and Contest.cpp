#include <cstdio>

#define getchar() (*_pinp?*_pinp++:(_inp[fread(_pinp=_inp, 1, 4096, stdin)]='\0', *_pinp++))
char _inp[4097], *_pinp=_inp;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int mult[200001];
int add[200001];
int M, N, Q;

void increment(int i, int inc_m, int inc_a)
{
	while (i < 200001)
	{
		mult[i] = (mult[i] + inc_m) % M;
		add[i] = (add[i] + inc_a) % M;
		i += i&-i;
	}
}

void update(int l, int r, int x)
{
	increment(l, x, -(l - 1)*x);
	increment(r + 1, -x, r*x);
}

int sum(int i)
{
	int m = 0;
	int a = 0;
	int tmp = i;
	while (tmp >= 1)
	{
		m += mult[tmp];
		a += add[tmp];
		tmp -= tmp&-tmp;
	}
	m %= M; a %= M;
	return (m*i + a) % M;
}


int query(int right, int left)
{
	return sum(left) - sum(right - 1);
}

int main()
{
	scan(M); scan(N); scan(Q);
	int a;
	for (int i = 1; i <= N; i++)
	{
		scan(a);
		a %= M;
		update(i, i, a);
	}
	int t, l, r, x;
	for (int i = 0; i < Q; i++)
	{
		scan(t);
		if (t == 1)
		{
			scan(l); scan(r); scan(x);
			x %= M;
			update(l, r, x);
		}
		else
		{
			scan(l); scan(r);
			int ans = (query(l, r)) % M;
			if (ans < 0) ans += M;
			printf("%d\n", ans);
		}
	}
	return 0;
}