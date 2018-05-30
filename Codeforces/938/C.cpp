#include <cstdio>
#include <cmath>
#define ll long long

int main()
{
	int t;
	ll x;
	scanf("%d", &t);
	while (t--) {
		scanf("%lld", &x);
		if (x == 1 || x % 4 == 2) {
			printf("-1\n");
			continue;
		}
		bool found = false;
		for (ll b = 1LL; b*b < x + 100000; b++) {
			ll a = (ll)sqrt(x + b * b);
			if (a*a == x + b * b) {
				ll m = a / b;
				if (a / m == b) {
					printf("%lld %lld\n", a, m);
					found = true;
					break;
				}
			}
		}
		if (!found)
			printf("-1\n");
	}
    return 0;
}
