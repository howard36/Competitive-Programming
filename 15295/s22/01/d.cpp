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

ll a[2003], psa[2003], mh[2003], mw[2003];

int main() { FAST
	int n, m;
	cin >> n >> m;
	for (int i = 0; i<n; i++) {
		cin >> a[i];
		psa[i+1] = psa[i] + a[i];
	}
	for (int h = 1; h<=n; h++) {
		mh[h] = 1e18;
		for (int i = 0; i+h<=n; i++)
			mh[h] = min(mh[h], psa[i+h] - psa[i]);
	}
	for (int i = 0; i<m; i++) {
		cin >> a[i];
		psa[i+1] = psa[i] + a[i];
	}
	for (int h = 1; h<=m; h++) {
		mw[h] = 1e18;
		for (int i = 0; i+h<=m; i++)
			mw[h] = min(mw[h], psa[i+h] - psa[i]);
	}
	ll s;
	cin >> s;
	int ans = 0;
	for (int h = 1; h<=n; h++) {
		for (int w = 1; w<=m; w++) {
			if (mh[h]*mw[w] <= s)
				ans = max(ans, h*w);
			else
				break;
		}
	}
	cout << ans << "\n";
}
