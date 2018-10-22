#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 998244353LL

ll a[100005], b[100005];
int n;
ll t;

ll add(ll a, ll b){return (a+b)%mod;}


bool good(ll mid) {
	if (mid == 0)
		return true;
	ll ans = 0;
	for (int i = 0; i < n; i++) {
        if (a[i] >= mid)
		    ans += (a[i] - mid) / b[i] + 1;
		if (ans >= t)
			return true;
	}
	return false;
}

int main() {
	scanf("%d %lld", &n, &t);
	for (int i = 0; i < n; i++) {
		scanf("%lld %lld", &a[i], &b[i]);
	}
	ll lo = 0, hi = 1e18;
	while (lo < hi) {
		ll mid = (lo + hi) / 2;
		if (good(mid)) {
			lo = mid + 1;
		}
		else {
			hi = mid;
		}
	}
    // printf("lo = %lld\n", lo);
	ll ans = 0;
	ll used = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] < lo)
			continue;
		ll num = (a[i] - lo) / b[i] + 1;
		used += num;
		num %= mod;
		ans += (((2*a[i]%mod - (num - 1)*(b[i]%mod) % mod) % mod)*num % mod) * ((mod + 1)/2) % mod;
		ans %= mod;
	}
	ans += ((lo - 1) % mod * ((t - used) % mod)) % mod;
    ans = ((ans % mod) + mod) % mod;
	printf("%lld\n", ans);
}