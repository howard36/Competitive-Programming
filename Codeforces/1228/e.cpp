#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007LL


ll fastexp(ll a, ll b) {
	ll ans = 1;
	while (b) {
		if (b%2 == 1) 
			ans = (ans*a)%mod;
		b /= 2;
		a = (a*a)%mod;
	}
	return ans;
}

ll ch[300][300], pk[100005], pl[100005];

ll m(ll a, ll b) { return (a*b) % mod; }

int main() {
	ll n, k;
	scanf("%lld %lld", &n, &k);
	if (k == 1) {
		printf("1");
		return 0;
	}

	ch[0][0] = 1;
	for (int i = 0; i<=n; i++) {
		for (int j = 0; j<=i; j++) {
			ch[i][j] %= mod;
			ch[i+1][j] += ch[i][j];
			ch[i+1][j+1] += ch[i][j];
		}
	}

	pk[0] = pl[0] = 1;
	for (int i = 1; i<100000; i++) {
		pk[i] = (pk[i-1] * k) % mod;
		pl[i] = (pl[i-1] * (k-1)) % mod;
	}

	ll ans = 0;
	for (int i = 0; i<=n; i++) {
		for (int j = 0; j<=n; j++) {
			ll x = m(m(m(ch[n][i], ch[n][j]), pl[i*n+j*n-i*j]), pk[(n-i)*(n-j)]);
			if ((i+j)%2 == 1)
				ans = (ans - x) % mod;
			else
				ans = (ans + x) % mod;
		}
	}
	if (ans < 0)
		ans += mod;
	printf("%lld", ans);
}
