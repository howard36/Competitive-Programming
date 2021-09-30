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

ll a[20];
const ll M = 1000000007;

ll mpow(ll base, ll exp) {
	if(exp == 0) return 1;
	ll res = 1;
	if(exp%2 == 1) res = base;
	ll val = mpow(base, exp/2);
	res *= val; res %= M;
	res *= val; res %= M;
	return res;
}

ll inv(ll a) {
	ll exp = M-2;
	ll pow = a;
	return mpow(pow, exp);
}

int main() { FAST
	int n;
	cin >> n;
	for (int i = 0; i<n; i++)
		cin >> a[i];
	ll ans = 0;
	for (int m = 0; m<(1<<n); m++) {
		ll p = 1, cnt = 0;
		for (int i = 0; i<n; i++) {
			for (int j = 0; j<n; j++) {
				if (((m>>i)&1) == 1 && ((m>>j)&1) == 0) {
					p += a[i] * inv(a[i]+a[j]) % M;
					p %= M;
				}
			}
			cnt += (m>>i)&1;
		}
		dbg(m _ p)
		ans = (ans + p * cnt) % M;
	}
	finish(ans);
	
}
