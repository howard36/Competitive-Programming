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


int main() { FAST
	ll a, b, x = 0, y = 0;
	cin >> a >> b;
	while (a%2 == 0) {
		x++;
		a /= 2;
	}
	while (b%2 == 0) {
		y++;
		b /= 2;
	}
	vector<pi> v;
	while (x < y) {
		v.pb(pi(0,0));
		x++;
	}
	while (x > y) {
		v.pb(pi(1,1));
		y++;
	}
	while (a != b) {
		if (a > b) {
			v.pb(pi(0,1));
			a += b;
			while (a%2 == 0) {
				a /= 2;
				x++;
				v.pb(pi(1,1));
				y++;
			}
		}
		else {
			v.pb(pi(1,0));
			b += a;
			while (b%2 == 0) {
				b /= 2;
				y++;
				v.pb(pi(0,0));
				x++;
			}
		}
	}
	cout << v.size() << endl;
	for (pi p : v) {
		char c1 = 'A' + p.f;
		char c2 = 'A' + p.s;
		cout << c1 << "+=" << c2 << endl;
	}
}
