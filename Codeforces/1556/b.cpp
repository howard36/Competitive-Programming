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

int a[100005];

int main() { FAST
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int even = 0, odd = 0;
		for (int i = 0; i<n; i++) {
			cin >> a[i];
			a[i] %= 2;
			if (a[i] == 0)
				even++;
			else
				odd++;
		}
		if (abs(even-odd) > 1) {
			cout << "-1\n";
			continue;
		}
		ll ans = 1e18;
		if (even - odd == 1) {
			ll moves = 0;
			int p = 0;
			for (int i = 0; i<n; i++) {
				if (a[i] == 0) {
					moves += abs(i-p);
					p += 2;
				}
			}
			ans = min(ans, moves);
		}
		if (even - odd == -1) {
			ll moves = 0;
			int p = 1;
			for (int i = 0; i<n; i++) {
				if (a[i] == 0) {
					moves += abs(i-p);
					p += 2;
				}
			}
			ans = min(ans, moves);
		}
		if (even - odd == 0) {
			ll moves = 0;
			int p = 0;
			for (int i = 0; i<n; i++) {
				if (a[i] == 0) {
					moves += abs(i-p);
					p += 2;
				}
			}
			ans = min(ans, moves);
			
			moves = 0;
			p = 1;
			for (int i = 0; i<n; i++) {
				if (a[i] == 0) {
					moves += abs(i-p);
					p += 2;
				}
			}
			ans = min(ans, moves);
		}
		cout << ans << endl;
	}
}
