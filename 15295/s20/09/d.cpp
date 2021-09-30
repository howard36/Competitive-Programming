#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()
#define sz(v) (int)v.size()

#define MOO(i, a, b) for(int i=a; i<b; i++)
#define M00(i, a) for(int i=0; i<a; i++)
#define MOOd(i,a,b) for(int i = (b)-1; i >= a; i--)
#define M00d(i,a) for(int i = (a)-1; i>=0; i--)

#define FAST ios::sync_with_stdio(0); cin.tie(0);
#define finish(x) return cout << x << '\n', 0;
#define dbg(x) // cerr << ">>> " << #x << " = " << x << "\n";
#define _ << " _ " <<

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ld,ld> pd;
typedef complex<ld> cd;

#define mod 10007

ll mpow(ll a, ll b) {
	ll p = a, ans = 1;
	while (b) {
		if (b%2)
			ans = ans*p%mod;
		p = p*p%mod;
		b /= 2;
	}
	return ans;
}

ll inv(ll a) { return mpow(a, mod-2); }

ll fac[1000006];

ll ch(ll n, ll k) {
	if (n < k)
		return 0;
	if (n < mod && k < mod)
		return fac[n]*inv(fac[k]*fac[n-k]%mod)%mod;
	else {
		ll n0 = n%mod, n1 = n/mod%mod, n2 = n/mod/mod;
		ll k0 = k%mod, k1 = k/mod%mod, k2 = k/mod/mod;
		return (ch(n0, k0) * ch(n1, k1) % mod) * ch(n2, k2) % mod;
	}
}

ll a[20];

int main() { FAST
	fac[0] = 1;
	for (int i = 1; i<1000006; i++)
		fac[i] = i*fac[i-1]%mod;
	int t;
	cin >> t;
	while (t--) {
		ll n, p, q, m;
		cin >> n >> p >> q >> m;
		for (int i = 0; i<p+q; i++)
			cin >> a[i];
		for (int i = p; i<p+q; i++)
			m -= a[i];
		m -= n-q;

		ll ans = 0;
		for (int msk = 0; msk < (1<<p); msk++) {
			ll req = m, sgn = 1;
			for (int i = 0; i<p; i++) {
				if ((msk>>i)&1) {
					req -= a[i];
					sgn *= -1;
				}
			}
			dbg(req _ m);
			if (req >= 0) {
				ans = (ans + sgn*ch(req+n-1, n-1))%mod;
			}
		}
		cout << (ans%mod + mod)%mod << endl;
	}
}
