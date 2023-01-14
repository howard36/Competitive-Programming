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

ld a[30], psa[30];
cd ans[30];

int main() { FAST
	int n;
	cin >> n;
	for (int i = 0; i<n; i++) {
		cin >> a[i];
	}
	for (int i = n-1; i>=0; i++) {
		psa[i] = psa[i+1] + a[i];
	}
	ld x, y;
	cin >> x >> y;
	cd target = cd(x,y);
	ld d = abs(target);
	if (n == 1) {
		// TODO
	} else {
		sort(a, a+n);
		ld b = a[n-1], c = a[n-2];
		for (int i = 0; i<n-2; i++) {
			if (d - a[i] >= b-c) {
				ans[i] = cd(a[i], 0);
				d -= a[i];
			} else {
				ans[i] = cd(-a[i], 0);
				d += a[i];
			}
		}
		if (b+c <= d) {
			ans[n-1] = cd(b,0);
			ans[n-2] = cd(c,0);
		} else if (d <= b-c) {
			ans[n-1] = cd(b,0);
			ans[n-2] = cd(-c,0);
		} else {
			ans[n-1] = 
		}
	}
}
