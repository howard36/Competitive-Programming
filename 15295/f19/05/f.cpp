#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int, int>
#define pl pair<ll, ll>

int a[200005];
ll dp[200005];

int main() {
	int m;
	scanf("%d", &m);
	for (int i = 0; i<m; i++) {
		int x;
		scanf("%d", &x);
		if (x == 0)
			a[i] = 0;
		else if (x > 0)
			a[i] = 1;
		else
			a[i] = -1;
	}
	ll p = 0, n = 0, z = 0;
	if (a[0] == 0)
		z++;
	else if (a[0] > 0)
		p++;
	else
		n++;
	ll Z = z, P = p, N = n;
	for (int i = 1; i<m; i++) {
		if (a[i] == 0) {
			z = i+1;
			p = n = 0;
		}
		else if (a[i] > 0) {
			p++;
		}
		else {
			swap(p, n);
			n++;
		}
		Z += z;
		P += p;
		N += n;
	}
	printf("%lld %lld %lld", N, Z, P);
}
