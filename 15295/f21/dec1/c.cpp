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

int w[1003];
ld s[1003], t[1003], dp[1003];

int main() { FAST
	ll W, n;
	ld L;
	cin >> W >> L >> n;
	for (int i = 0; i<n; i++) {
		cin >> w[i] >> s[i];
		t[i] = L/s[i];
	}
	for (int i = 0; i<n; i++) {
		dp[i] = 1e50;
		ll tw = 0;
		ld maxt = 0;
		for (int j = i; j >= 0; j--) {
			tw += w[j];
			maxt = max(maxt, t[j]);
			if (tw > W)
				break;
			if (j > 0)
				dp[i] = min(dp[i], dp[j-1] + maxt);
			else
				dp[i] = min(dp[i], maxt);
		}
	}
	cout << fixed << setprecision(10) << dp[n-1] * 60 << endl;
}
