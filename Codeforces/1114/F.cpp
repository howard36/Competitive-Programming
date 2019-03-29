#include <bits/stdc++.h>
#define MAXN 400005
#define ll long long
using namespace std;
#define MOD 1000000007

int isprime[300];
vector<int> primes;
ll bit[62][2][MAXN];

ll fastPow(ll b, int e) {
	ll ans = 1, power = b;
	while (e) {
		if (e & 1) {
			ans *= power;
			ans %= MOD;
		}
		power = (power * power) % MOD;
		e /= 2;
	}
	return ans;
}

void update(int p, int t, int i, ll v) {
	for (; i < MAXN; i += (i & -i)) {
		bit[p][t][i] += v;
	}
}

ll query(int p, int t, int i) {
	ll ans = 0;
	for (; i > 0; i -= (i & -i))
		ans += bit[p][t][i];
	return ans;
}

ll range(int p, int l, int r) {
	// if (p < 3) {
	// 	printf("query(%d, 1, %d) = %lld\n", p, r, query(p, 1, r));
	// 	printf("query(%d, 0, %d) = %lld\n", p, r, query(p, 0, r));
	// 	printf("query(%d, 1, %d) = %lld\n", p, l - 1, query(p, 1, l - 1));
	// 	printf("query(%d, 0, %d) = %lld\n", p, l - 1, query(p, 0, l - 1));
	// }
	return (query(p, 1, r) * r + query(p, 0, r)) - (query(p, 1, l - 1) * (l - 1) + query(p, 0, l - 1));
}

int main() {
	int n, q;
	scanf("%d %d", &n, &q);
	for (ll i = 2; i < 300; i++) {
		isprime[i] = 1;
	}
	// printf("Hi1\n");
	for (ll i = 2; i < 300; i++) {
		if (isprime[i]) {
			primes.push_back(i);
			for (ll j = i * i; j < 300; j += i)
				isprime[j] = 0;
		}
	}
	// printf("Hi1\n");
	int a;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		for (int j = 0; j < primes.size(); j++) {
			if (a % primes[j] != 0)
				continue;
			int vp = 0;
			while (a % primes[j] == 0) {
				a /= primes[j];
				vp++;
			}
			// printf("Hi2 %d %d %d\n", j, i, vp);
			update(j, 0, i + 1, vp);
			// update(j, 0, i + 2, -vp);
		}
	}
	while (q--) {
		string s;
		cin >> s;
		int l, r, x;
		if (s[0] == 'M') {
			scanf("%d %d %d", &l, &r, &x);
			for (int j = 0; j < primes.size(); j++) {
				if (x % primes[j] != 0)
					continue;
				int vp = 0;
				while (x % primes[j] == 0) {
					x /= primes[j];
					vp++;
				}
				update(j, 1, l, vp);
				update(j, 1, r + 1, -vp);
				update(j, 0, l, -(l - 1) * vp);
				update(j, 0, r + 1, r * vp);
			}
		}
		else {
			scanf("%d %d", &l, &r);
			ll ans = 1;
			for (int j = 0; j < primes.size(); j++) {
				ll vp = range(j, l, r);
				if (vp) {
					ans *= fastPow(primes[j], vp-1);
					ans %= MOD;
                    ans *= primes[j] - 1;
                    ans %= MOD;
				}
			}
			printf("%lld\n", ans);
		}
	}
}