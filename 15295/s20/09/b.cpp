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
#define dbg(x) cerr << ">>> " << #x << " = " << x << "\n";
#define _ << " _ " <<

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ld,ld> pd;
typedef complex<ld> cd;

#define mod 1000000007LL

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

ll ch(ll n, ll k) { return fac[n]*inv(fac[k]*fac[n-k]%mod)%mod; }

int main() { FAST
	fac[0] = 1;
	for (int i = 1; i<1000006; i++)
		fac[i] = i*fac[i-1]%mod;
	ll n, k;
	cin >> n >> k;	
	ll x = ch(n+k-1, k-1);
	cout << (x%mod+mod)%mod << endl;
}
