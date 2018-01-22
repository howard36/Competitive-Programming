#include <cstdio>
using namespace std;
int BIT[500001], rating[500001], ps[500001];
int N, Q;

int sum(int i)
{
	int ans = 0;
	for (; i >= 1; i -= i&-i)
		ans += BIT[i];
	return ans;
}

void increment(int i, int inc)
{
	for (; i <= N; i += i&-i)
		BIT[i] += inc;
}

int query(int left, int right)
{
	return sum(right) - sum(left - 1);
}

int main()
{
	scanf("%d %d", &N, &Q);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &rating[i]);
		ps[i] = rating[i] + ps[i - 1];
	}
	for (int i = 1; i <= N; i++)
		BIT[i] = ps[i] - ps[i - (i&-i)];
	int a, b;
	while (Q--)
	{
		scanf("%d %d", &a, &b);
		printf("%d\n", ps[N] - query(a, b));
	}
    return 0;
}