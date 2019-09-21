#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ll N, n, a, b, t;
	scanf("%lld", &N);
	while (N--) {
		scanf("%lld %lld %lld %lld", &n, &a, &b, &t);
		if (a*n < t)
			printf("-1\n");
		else
			printf("%lld\n", (t+b*n+a+b-1)/(a+b));
	}
}
