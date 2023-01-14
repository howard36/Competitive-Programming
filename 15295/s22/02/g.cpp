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
typedef pair<ll,int> pl;

int a[1000006], lmax[1000006], rmax[1000006], ql[1000006], qr[1000006];
pi ss[1<<21];

pl query(int i, int l, int r, int tl, int tr) {
	if (r < tl || tr < l) return mp(0,-1);
	if (tl == tr) return mp(1,tl);
	int tm = (tl + tr)/2;
	pl al = query(2*i, l, r, tl, tm);
	pl ar = query(2*i+1, l, r, tm+1, tr);
	ll fl = al.f, fr = ar.f;
	int ml = al.s, mr = ar.s;
	if (ml == -1) return ar;
	if (mr == -1) return al;
	if (a[ml] > a[mr]) {
		ll f = fl + fr + 1LL*(min(tr,r)-tm+1)*
		return 
	} else {

	}
}

int main() { FAST
	int n, q;
	cin >> n >> q;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int k = 0;
	while ((1<<k) < n) k++;
	for (int i = 0; i < n; i++)
		ss[(1<<k)+i] = mp(a[i], i);
	for (int i = 1<<k; i > 0; i--)
		ss[i] = max(ss[2*i], ss[2*i+1]);

	stack<pi> s1;
	s1.push(mp(n+1, -1));
	for (int i = 0; i<n; i++) {
		while (s1.top().f < a[i])
			s1.pop();
		lmax[i] = s1.top().s;
		s1.push(mp(a[i],i));
	}
	stack<pi> s2;
	s2.push(mp(n+1, n));
	for (int i = n-1; i>=0; i--) {
		while (a[i] > s2.top().f)
			s2.pop();
		rmax[i] = s2.top().s;
		s2.push(mp(a[i],i));
	}

	for (int i = 0; i<q; i++)
		cin >> ql[i];
	for (int i = 0; i<q; i++)
		cin >> qr[i];
	for (int i = 0; i<q; i++)
		cout << query(1, ql[i], qr[i], 0, 1<<20) << " ";
	cout << endl;
}
