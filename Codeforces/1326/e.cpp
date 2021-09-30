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

pi st[1<<20];
int ans[300005], q[300005];

pi query(int i, int tl, int tr, int ql, int qr) {
	//assert(i > 0);
	dbg(i _ tl _ tr _ ql _ qr);
	dbg(st[i].f _ st[i].s);
	if (qr <= tl || tr <= ql) {
		dbg(tl _ tr _ "bad");
		return pi(1e9, -1);
	}
	if (ql <= tl && tr <= qr) {
		dbg(tl _ tr _ "good");
		return st[i];
	}
	int mid = (tl + tr)/2;
	pi p1 = query(2*i, tl, mid, ql, qr);
	pi p2 = query(2*i+1, mid, tr, ql, qr);
	dbg(tl _ tr _ p1.f _ p2.f);
	return min(p1, p2);
}

void upd(int i) {
	i += 1<<19;
	st[i] = pi(1e9, -1);
	for (i/=2; i>0; i/=2)
		st[i] = min(st[2*i], st[2*i+1]);
}

int main() { FAST
	int n;
	cin >> n;
	int a;
	for (int i = 0; i<n; i++) {
		cin >> a;
		st[(1<<19) + i] = pi(a, i);
	}
	for (int i = n; i<(1<<19); i++)
		st[(1<<19) + i] = pi(1e9, i);
	for (int i = (1<<19)-1; i>0; i--) 
		st[i] = min(st[2*i], st[2*i+1]);
	for (int i = 0; i<n; i++)
		cin >> q[i];
	for (int i = n-1; i>=0; i--) {
		int idx = query(1, 0, 1<<19, q[i]-1, n).s;
		dbg(idx);
		ans[i] = max(ans[i+1], st[(1<<19) + idx].f);
		upd(idx);
	}
	for (int i = 0; i<n; i++)
		cout << ans[i] << " ";
	cout << endl;
}
