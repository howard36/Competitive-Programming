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

int w[10004];
pi a[10004];
int b[10004];

int main() { FAST
	int n, k;
	cin >> n >> k;
	int sw = 0;
	for (int i = 0; i<n; i++) {
		w[i] = (1<<k)-1;
		sw += w[i];
	}
	while (sw) {
		for (int i = 0; i<n; i++) {
			cin >> b[i];
			a[i] = mp(b[i], w[i]);
		}
		sort(a, a+n);
		int i = 0;
		for (int psa = 0; i<n; i++) {
			psa += a[i].s;
			if (2*psa >= sw) {
				cout << a[i].f << endl;
				break;
			}
		}
		string s;
		cin >> s;
		if (s[0] == 'E')
			break;
		else if (s[0] == '>') {
			for (int j = 0; j<n; j++)
				if (b[j] >= a[i].f)
					w[j] /= 2;
		} else {
			for (int j = 0; j<n; j++)
				if (b[j] <= a[i].f)
					w[j] /= 2;
		}
		sw = 0;
		for (int j = 0; j<n; j++)
			sw += w[j];
		dbg(sw)
	}
}
