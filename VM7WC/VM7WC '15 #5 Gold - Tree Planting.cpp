#include <cstdio>
#define ll long long
using namespace std;
const int mod = 1000000007;
ll BIT[2002][2002];

ll sum(int i, int diag)
{
	ll ans = 0;
	for (; i >= 1; i -= i&-i)
		ans = (ans + BIT[diag][i]) % mod;
	return ans;
}

void increment(int i, int inc, int diag)
{
	for (; i <= diag; i += i&-i)
		BIT[diag][i] = (BIT[diag][i] + inc) % mod;
}

ll query(int left, int right, int diag)
{
	return sum(right, diag) - sum(left - 1, diag);
}

int main()
{
	int N, type, r, c, x, ans;
	scanf("%d", &N);
	while (N--)
	{
		scanf("%d %d %d %d", &type, &r, &c, &x);
		if (type == 1)
			increment(r, x, r + c - 1);
		else
			ans = (ans + query(r - x, r, r + c - 1)) % mod;
	}
	printf("%d", ans);
    return 0;
}