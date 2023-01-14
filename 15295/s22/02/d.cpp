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

int d[1<<16], x[1<<16];
set<pi> s;

int main() { FAST
	int n;
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> d[i] >> x[i];
		if (d[i])
			s.insert(mp(d[i], i));
		sum += d[i];
	}
	cout << sum/2 << endl;
	while (!s.empty()) {
		pi p = *s.begin();
		int i = p.s;
		int j = x[i];
		s.erase(mp(d[i], i));
		s.erase(mp(d[j], j));
		printf("%d %d\n", i, j);
		d[j]--;
		x[j] ^= i;
		if (d[j])
			s.insert(mp(d[j], j));
	}
}
