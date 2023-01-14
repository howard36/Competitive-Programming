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
#define dbg(x) //cerr << ">>> " << #x << " = " << x << "\n";
#define _ << " _ " <<

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ld,ld> pd;
typedef complex<ld> cd;

int bit[1<<20+1];

void add(int i, int v) {
	dbg("add" _ i _ v);
	for (; i<=(1<<20); i+=i&-i)
		bit[i] += v;
}

void rem(int k) {
	int l = 0, s = 1<<19;
	for (int s = 1<<19; s > 0; s /= 2) {
		dbg(l _ s _ k);
		if (bit[l+s] < k) {
			k -= bit[l+s];
			l += s;
		}
	}
	add(l+1, -1);
}

int main() { FAST
	int n, q;
	cin >> n >> q;
	int x;
	for (int i = 0; i<n; i++) {
		cin >> x;
		add(x, 1);
	}
	for (int i = 0; i<q; i++) {
		cin >> x;
		if (x > 0)
			add(x, 1);
		else
			rem(-x);
	}
	for (int i = 0; i<=n; i++) {
		if (bit[i]) {
			finish(i);
		}
	}
	finish(0);
}
