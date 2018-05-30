#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1000000007;

unordered_map<ll, ll> mem;
vector<ll> divisors;
int prime[1000006];

ll phi(ll n) {
	if (mem.find(n) != mem.end())
		return mem[n];
	ll ans = n;
	for (ll& d : divisors) {
		if (n % d == 0 && d != n)
			ans -= phi(d);
	}
	mem[n] = ans;
	return ans;
}

ll pow2(ll exp) {
	ll ans = 1, pow = 2;
	while (exp > 0)
	{
		if (exp & 1)
			ans = (ans * pow) % mod;
		exp >>= 1;
		pow = (pow * pow) % mod;
	}
	return ans;
}

int main()
{
	FILE *fin = fopen("gymnasts.in", "r");
	FILE *fout = fopen("gymnasts.out", "w");
	ll N;
	fscanf(fin, "%lld", &N);
	mem[1] = 1;

	divisors.push_back(1);
	for (ll d = 2; d*d <= N; d++) {
		if (N%d == 0) {
			divisors.push_back(d);
			if (d*d < N)
				divisors.push_back(N / d);
		}
	}
	ll ans = 1;
	for (ll& d : divisors) {
		ans += (pow2(d) - 1) * (phi(N / d) % mod);
		ans %= mod;
	}
	fprintf(fout, "%lld", ans);
	return 0;
}
