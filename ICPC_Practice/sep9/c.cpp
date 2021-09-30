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

ll a[300005], b[300005], s[300005], inva[300005], invb[300005];
ll ans[2][300005];

int main() { FAST
	ll n, k;
	cin >> n >> k;
	for (int i = 1; i<=n; i++)
		cin >> a[i];
	for (int i = 1; i<=n; i++)
		cin >> b[i];
	if (n == 1) {
		cout << "Yes\n0\n0\n";
		return 0;
	}
	for (int i = 1; i<=n; i++) {
		inva[a[i]] = i;
		invb[b[i]] = i;
	}
	for (int i = 1; i<=n; i++) {
		if (k > n-inva[i]) {
			k -= n-inva[i];
			ans[0][inva[i]] = -n;
			continue;
		}
		if (k == -1) {
			ans[0][inva[i]] = n;
			continue;
		}
		for (int j = 1; j<=n; j++)
			s[j] = 0;
		for (int j = inva[i]+1; j<=n; j++)
			s[b[j]] = 1;
		int maxj = -1;
		for (int j = 1; j<=n; j++)
			if (s[j] && k) {
				maxj = j;
				k--;
			}
		for (int j = 1; j<=n; j++)
			ans[1][j] = (b[j] <= maxj) ? -1 : 1;
		ans[0][inva[i]] = 0;
		k = -1;
	}
	cout << "Yes" << endl;
	for (int t = 0; t<2; t++) {
		for (int i = 1; i<n; i++)
			cout << ans[t][i] << " ";
		cout << ans[t][n] << endl;
	}
}
