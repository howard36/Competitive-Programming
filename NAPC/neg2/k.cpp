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

ll p;

ll mpow(ll a, ll b) {
	ll ans = 1, poww = a;
	while (b) {
		if (b%2)
			ans = ans*poww%p;
		poww = poww*poww%p;
		b /= 2;
	}
	return ans;
}

int qr[100005];

int main() { FAST
	cin >> p;
	if (p == 2) {
		finish(0);
	}
	qr[0] = 1;
	for (int i = 1; i<p; i++) {
		if (mpow(i, (p-1)/2) == 1)
			qr[i] = 1;
		else
			qr[i] = 0;
	}
	int ans = 0;
	for (int x = 0; x<p; x++) {
		int a = 0;
		while (qr[((x-a*a)%p+p)%p] == 0) a++;
		ans = max(ans, a);
	}
	cout << ans << endl;
}
