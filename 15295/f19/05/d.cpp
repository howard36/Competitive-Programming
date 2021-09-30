#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int, int>

ll t[3][3];

void mult(ll a[3][3], ll b[3][3], ll c[3][3], ll m) {
	for (int i = 0; i<3; i++) {
		for (int j = 0; j<3; j++) {
			c[i][j] = 0;
			for (int k = 0; k<3; k++)
				c[i][j] += a[i][k] * b[k][j];
			c[i][j] %= m;
		}
	}
}

void copy(ll a[3][3], ll b[3][3]) {
	for (int i = 0; i<3; i++)
		for (int j = 0; j<3; j++)
			a[i][j] = b[i][j];
}

void fastexp(ll a[3][3], ll b, ll m) {
	ll ans[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
	while (b > 0) {
		if (b%2 == 1) {
			mult(ans, a, t, m);
			copy(ans, t);
		}
		mult(a, a, t, m);
		copy(a, t);
		b /= 2;
	}
	copy(a, ans);
}

ll d, a1, a2, L, R;

ll f(ll m) {
	ll M[3][3] = {{1, 1, 1}, {0, 1, 1}, {0, 1, 0}};
	fastexp(M, d-2, m);
	return ((a1 + a2)*M[0][0] + a2*M[0][1] + a1*M[0][2])%m;
}

int main() {
	scanf("%lld%lld%lld%lld%lld", &a1, &a2, &d, &L, &R);
	ll ans = 1e18;
	for (int m = L; m <= R; m++) {
		ans = min(ans, f(m));
	}
	printf("%lld\n", ans);
}
