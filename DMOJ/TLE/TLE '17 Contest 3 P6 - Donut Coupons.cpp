#include <cstdio>
#define ll long long
using namespace std;
const ll M = 1000000007;

int mult[200001];
int add[200001];
int N;

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

ll pow(ll b, int exp)
{
	ll i = 1LL;
	while (exp--)
		i = (i*b) % M;
	return i;
}

ll arr[1003];
int main()
{
	int Q, l, r, k; char c;
	scanf("%d%d", &N, &Q);
	if (N <= 1000 && Q <= 1000)
	{
		while (Q--)
		{
			scanf(" %c", &c);
			if (c == 'U')
			{
				scanf("%d%d%d", &l, &r, &k);
				for (int i = 1; i <= r - l + 1; i++)
					arr[i + l - 1] = (arr[i + l - 1] + pow(i, k)) % M;
			}
			else
			{
				scanf("%d%d", &l, &r);
				ll sum = 0LL;
				for (int i = l; i <= r; i++)
					sum = (sum + arr[i]) % M;
				printf("%d\n", sum);
			}
		}
	}
	else
	{
		while (Q--)
		{
			scanf(" %c", &c);
			if (c == 'U')
			{
				scanf("%d%d%d", &l, &r, &k);
				update(l, r, 1);
			}
			else
			{
				scanf("%d%d", &l, &r);
				printf("%d\n", query(l,r)%M);
			}
		}
	}
    return 0;
}