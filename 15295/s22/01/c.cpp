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

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
	return a*b/gcd(a,b);
}

int main() { FAST
	int t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		auto ans = mp((ll)1e18, mp(0LL, 0LL));
		for (ll i = 1; i*i <= n; i++) {
			if (n%i == 0) {
				ans = min(ans, mp(lcm(i, n-i), mp(i, n-i)));
				if (i > 1)
					ans = min(ans, mp(lcm(n/i, n-n/i), mp(n/i, n-n/i)));
			}
		}
		cout << ans.s.f << " " << ans.s.s << "\n";
	}
}
