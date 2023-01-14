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
#define dbg(x) // cerr << ">>> " << #x << " = " << x << "\n";
#define _ << " _ " <<

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ld,ld> pd;
typedef complex<ld> cd;

unordered_set<int> s[200005], app[200005];
int satis[200005], ans[200005], varset[200005];

bool setvar(int);

bool setsatis(int ss) {
	dbg("setsatis" _ ss)
	satis[ss] = 1;
	for (int x : s[ss]) {
		int ax = abs(x);
		if (varset[ax])
			continue;
		if (sz(app[ax]) == 2) {
			app[ax].erase(x > 0 ? ss : -ss);
			int ss2 = *app[ax].begin();
			if (!setvar(ss2 > 0 ? ax : -ax))
				return false;
		}
	}
	return true;
}

bool setvar(int x) {
	dbg("setvar" _ x)
	int ax = abs(x);
	if (varset[ax])
		return true;
	varset[ax] = 1;
	if (x > 0)
		ans[ax] = 1;
	for (int ss : app[ax]) {
		int as = abs(ss);
		if (satis[as])
			continue;
		if (1LL * ss * x < 0) {
			s[as].erase(-x);
			if (sz(s[as]) == 0)
				return false;
			if (sz(s[as]) == 1) {
				int y = *s[as].begin();
				if (!varset[y]) {
					if (!setvar(y))
						return false;
				}
			}
		} else {
			if (!setsatis(as))
				return false;
		}
	}
	return true;
}

int main() { FAST
	int n, m;
	cin >> n >> m;
	for (int i = 1; i<=n; i++) {
		int ki;
		cin >> ki;
		while (ki--) {
			int x;
			cin >> x;
			s[i].insert(x);
			app[abs(x)].insert(x > 0 ? i : -i);
		}
	}

	for (int i = 1; i <= m; i++) {
		if (varset[i])
			continue;
		if (sz(app[i]) == 1) {
			int ss = *app[i].begin();
			if (!setvar((ss > 0) ? i : -i)) {
				finish("NO");
			}
		} else if (sz(app[i]) == 2) {
			auto it = app[i].begin();
			int s1 = *it;
			++it;
			int s2 = *it;
			if (1LL * s1 * s2 > 0) {
				if (!setvar((s1 > 0) ? i : -i)) {
					finish("NO");
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (satis[i])
			continue;
		if (sz(s[i]) == 1) {
			int x = *s[i].begin();
			if (!setvar(x)) {
				finish("NO");
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (satis[i])
			continue;
		if (sz(s[i]) == 0) {
			finish("NO");
		}
		int x = *s[i].begin();
		setvar(x);
	}

	cout << "YES\n";
	for (int i = 1; i<=m; i++)
		cout << ans[i];
	cout << '\n';
}
