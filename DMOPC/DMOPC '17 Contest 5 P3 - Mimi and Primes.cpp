#include <cstdio>
#define ll long long

ll gcd(ll a, ll b)
{
	while (b != 0)
	{
		ll t = b;
		b = a % b;
		a = t;
	}
	return a;
}

int main()
{
	int N; ll cur = 0, num;
	scanf("%d", &N);
	while (N--) {
		scanf("%lld", &num);
		cur = gcd(cur, num);
	}
	if (cur == 1)
		printf("DNE");
	else {
		for (ll d = 2; d*d <= cur; d++) {
			while (cur%d == 0) {
				cur /= d;
			}
			if (cur == 1) {
				printf("%lld", d);
				return 0;
			}
		}
		printf("%lld", cur);
	}
    return 0;
}