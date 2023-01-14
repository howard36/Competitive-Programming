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

ll k[102], h[102], l[102];

int main() { FAST
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 0; i<n; i++)
			cin >> k[i];
		for (int i = 0; i<n; i++)
			cin >> h[i];
		l[n] = 1e9;
		for (int i = n-1; i>=0; i--)
			l[i] = min(k[i]-h[i], l[i+1]);

		vector<ll> v{ h[0] };
		for (int i = 0; i<n-1; i++) {
			if (l[i+1] < k[i]) {
				v.pop_back();
				l[i+1] = min(l[i+1], l[i]);
			}
			v.pb(k[i+1]-l[i+1]);
		}
		ll ans = 0;
		for (ll i : v) {
			ans += i*(i+1)/2;
		}
		cout << ans << endl;
	}
}
