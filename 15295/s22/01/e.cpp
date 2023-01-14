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

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

int ps[100], vp[100], a[100005][100], b[100];
ll n, k, m = 0;

bool good() {
	for (int i = 0; i<m; i++)
		if (b[i] < vp[i])
			return false;
	return true;
}

int main() { FAST
	cin >> n >> k;
	if (k == 1) {
		finish(n*(n+1)/2);
	}
	ll kk = k;
	for (int i = 2; i*i <= kk; i++) {
		if (kk%i == 0) {
			while (kk%i == 0) {
				vp[m]++;
				kk /= i;
			}
			ps[m] = i;
			m++;
		}
	}
	if (kk > 1) {
		vp[m]++;
		ps[m] = kk;
		m++;
	}
	for (int i = 0; i<n; i++) {
		int x;
		cin >> x;
		x = gcd(x, k);
		for (int j = 0; j<m; j++) {
			while (x%ps[j] == 0) {
				a[i][j]++;
				x /= ps[j];
			}
		}
	}
	int r = 0;
	ll ans = 0;
	for (int l = 0; l<n; l++) {
		while (r < n && !good()) {
			for (int i = 0; i<m; i++)
				b[i] += a[r][i];
			r++;
		}
		if (good()) {
			ans += n-r+1;
		}
		for (int i = 0; i<m; i++)
			b[i] -= a[l][i];
	}
	finish(ans);
}
