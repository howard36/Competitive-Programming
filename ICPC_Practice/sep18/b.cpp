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
typedef pair<pair<ld,int>,pd> ppd;
typedef vector<pd> vpd;
typedef vector<ppd> vppd;
typedef complex<ld> cd;

ld a[4003], b[4003], c[4003];
bool side[2][9], cross[2][9];
pd inter[2][9], vert[9];
const ld eps = 1e-6;
ld m;

ld area(vpd v) {
	v.pb(v[0]);
	ld a = 0;
	for (int i = 0; i<sz(v)-1; i++)
		a += v[i].f * v[i+1].s - v[i].s * v[i+1].f;
	return abs(a)/2;
}

ppd foo(pd p, int t) {
	return mp(mp(atan2(p.f - m/2, p.s - m/2), t), p);
}

int main() { FAST
	int z;
	cin >> z;
	while (z--) {
		int n;
		cin >> n >> m;
		for (int i = 0; i<n; i++) {
			cin >> a[i] >> b[i] >> c[i];
		}
		if (n >= 3) {
			cout << "100.000000%\n";
			continue;
		}
		vert[0] = pd(0,0);
		vert[1] = pd(m,0);
		vert[2] = pd(m,m);
		vert[3] = pd(0,m);
		for (int i = 0; i<4; i++)
			vert[i+4] = vert[i];

		for (int i = 0; i<n; i++) {
			for (int j = 0; j<5; j++)
				side[i][j] = (a[i]*vert[j].f + b[i]*vert[j].s + c[i] >= 0);
			for (int j = 0; j<4; j++) {
				cross[i][j] = (side[i][j] != side[i][j+1]);
			}
			if (cross[i][0])
				inter[i][0] = pd(-c[i]/a[i], 0);
			if (cross[i][1])
				inter[i][1] = pd(m, -(a[i]*m+c[i])/b[i]);
			if (cross[i][2])
				inter[i][2] = pd(-(b[i]*m+c[i])/a[i], m);
			if (cross[i][3])
				inter[i][3] = pd(0, -c[i]/b[i]);
			for (int j = 0; j<4; j++) {
				cross[i][j+4] = cross[i][j];
				inter[i][j+4] = inter[i][j];
			}
		}
		ld ans = m*m;
		if (n == 1) {
			for (int i = 0; i<4; i++) {
				if (cross[0][i] && cross[0][i+1]) {
					vpd v;
					v.pb(inter[0][i]);
					v.pb(vert[i+1]);
					v.pb(inter[0][i+1]);
					ans = area(v);
					break;
				}
				if (cross[0][i] && cross[0][i+2]) {
					vpd v;
					v.pb(inter[0][i]);
					v.pb(vert[i+1]);
					v.pb(vert[i+2]);
					v.pb(inter[0][i+2]);
					ans = min(area(v), ans);
				}
			}
		}
		else {
			ld det = a[0]*b[1] - a[1]*b[0];
			if (abs(det) < eps)
				ans = 0;
			else {
				ld ix = (b[0]*c[1] - b[1]*c[0])/det;
				ld iy = -(a[0]*c[1] - a[1]*c[0])/det;
				if (ix < 0 || ix > m || iy < 0 || iy > m)
					ans = 0;
				else {
					pd mid = mp(ix, iy);
					vppd v;
					for (int i = 0; i<4; i++) {
						v.pb(foo(vert[i], 0));
						for (int j = 0; j<2; j++)
							if (cross[j][i])
								v.pb(foo(inter[j][i], 1));
					}
					sort(all(v));
					for (int i = 0; i<8; i++)
						v.pb(v[i]);
					vpd v2;
					for (int i = 0; i<16; i++) {
						ppd p = v[i];
						if (p.f.s || !v2.empty())
							v2.pb(p.s);
						if (p.f.s && sz(v2) > 1) {
							v2.pb(mid);
							ans = min(ans, area(v2));
							v2.clear();
							v2.pb(p.s);
						}
					}
				}
			}
		}
		cout << fixed << setprecision(6) << 100*(1 - ans/(m*m)) << "%\n";
	}
}
