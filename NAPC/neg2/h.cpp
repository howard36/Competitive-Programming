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

#define mod 998244353LL

ll a[300005], f[300005], dp[300005], psa[300005];

set<int> S;
int mx = 0;

void add(int i) {
	if (a[i] >= mx) return;
	if (f[a[i]] == 0)
		S.insert(a[i]);
	f[a[i]]++;
}

void rem(int i) {
	if (a[i] >= mx) return;
	if (f[a[i]] == 1)
		S.erase(a[i]);
	f[a[i]]--;
}

int main() { FAST
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		M00(i, n+3) f[i] = 0;
		for (int i = 0; i<n; i++) {
			cin >> a[i];
			f[a[i]]++;
		}
		mx = 0;
		while (f[mx] > 0) mx++; 
		M00(i, n+3) f[i] = 0;
		S.clear();
		dp[0] = 1;
		psa[0] = 1;
		int idx = 0;
		while (S.size() < mx) {
			add(idx);
			idx++;
		}
		dbg(idx);
		MOO(i, 1, idx) {
			dp[i] = 0;
			psa[i] = 1;
			dbg(i _ dp[i]);
		}
		int l = 0;
		for (int i = idx; i<=n; i++) {
			bool removed = false;
			while (l < i && S.size() == mx) {
				rem(l);
				l++;
				removed = true;
			}
			if (removed) {
				l--;
				add(l);
			}
			dp[i] = psa[l];
			psa[i] = (psa[i-1] + dp[i])%mod;
			add(i);
			dbg(i _ dp[i]);
		}
		cout << dp[n] << endl;
	}
}
