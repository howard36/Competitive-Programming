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

ll a[100005], b[100005], psa[100005], s[2][17][100005];

int main() { FAST
	int n, q;
	cin >> n >> q;
	for (int i = 0; i<n; i++)
		cin >> a[i];
	for (int i = 0; i<n; i++)
		cin >> b[i];
	for (int i = 0; i<n; i++)
		psa[i+1] = psa[i] + a[i] - b[i];

	for (int i = 0; i<=n; i++)
		s[0][0][i] = s[1][0][i] = psa[i];
	for (int j = 0; j<16; j++) {
		for (int i = 0; i<=n; i++) {
			s[0][j+1][i] = min(s[0][j][i], s[0][j][i+(1<<j)]);
			s[1][j+1][i] = max(s[1][j][i], s[1][j][i+(1<<j)]);
		}
	}

	while (q--) {
		int l, r;
		cin >> l >> r;
		l--;
		if (psa[l] != psa[r]) {
			cout << "-1\n";
			continue;
		}
		int k = 0;
		while ((1<<k) <= r-l) k++;
			k--;
		ll m = min(s[0][k][l+1], s[0][k][r-(1<<k)+1]);
		ll M = max(s[1][k][l+1], s[1][k][r-(1<<k)+1]);
		if (M != psa[r])
			cout << "-1\n";
		else
			cout << psa[r] - m << endl;
	}
}
