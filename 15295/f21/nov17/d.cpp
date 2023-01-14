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

ld eps = 1e-11;

int main() { FAST
	ll n, q;
	cin >> n >> q;
	while (q--) {
		ld x1, x2, y1, y2, m = 1e100;
		cin >> x1 >> y1 >> x2 >> y2;
		if (x1 == x2)
			m = abs(x1);
		else if (y1 == y2)
			m = abs(y1);
		else {
			ld s = (y1-y2)/(x1-x2);
			ld x0 = y1 - x1*s;
			ld y0 = x1 - y1/s;
			m = min(abs(x0), abs(y0));
		}
		ll intm = int(m+eps);
		if (abs(m - intm) < eps) {
			cout << max(0LL, min(2*n, 2*(n-intm)+1)) << "\n";
		}
		else 
			cout << max(0LL, min(2*n, 2*(n-intm))) << "\n";
	}
}
