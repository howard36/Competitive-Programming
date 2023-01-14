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

int a[200005], psa[200005], b[200005];

int round(int x) {
	int k = 0;
	while ((1<<k) < x)
		k++;
	return 1<<k;
}

int solve(int p, int m) {
	int l, r, ans = 1e9;
	for (l = 0; psa[l] <= p; l++) {}
	l--;
	for (r = l; r<=m; r++)
		ans = min(ans, p + round(psa[r]-psa[l]) + round(psa[m]-psa[r]));
	for (r = m; psa[m]-psa[r] <= p; r--) {}
	r++;
	for (l = 0; l<=r; l++)
		ans = min(ans, round(psa[l]) + round(psa[r]-psa[l]) + p);
	r = 0;
	for (l = 0; l<m; l++) {
		while (r < m && psa[r+1]-psa[l] <= p)
			r++;
		ans = min(ans, round(psa[l]) + p + round(psa[m]-psa[r]));
	}
	return ans;
}

int main() { FAST
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 0; i<n; i++)
			cin >> a[i];
		sort(a, a+n);
		a[n] = 0;
		vector<int> v;
		b[0] = 1;
		for (int i = 1; i<=n; i++) {
			if (a[i] == a[i-1])
				b[i] = b[i-1] + 1;
			else {
				b[i] = 1;
				v.pb(b[i-1]);
			}
		}
		int m = sz(v);
		psa[0] = 0;
		for (int i = 1; i<=m; i++)
			psa[i] = psa[i-1] + v[i-1];
		int k = 0;
		while ((1<<k) < n)
			k++;
		int ans = (1<<k) + 2;
		if (k >= 1)
			ans = min(ans, solve(1<<(k-1), m));
		if (k >= 2)
			ans = min(ans, solve(1<<(k-2), m));
		cout << ans-n << endl;
	}
}
