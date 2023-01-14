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

string s[100];

int main() { FAST
	int t;
	cin >> t;
	while (t--) {
		int n, m, r, c;
		cin >> n >> m >> r >> c;
		for (int i = 0; i<n; i++) {
			cin >> s[i];
		}
		bool two = false, one = false, zero = false;
		for (int i = 0; i<n; i++) {
			for (int j = 0; j<m; j++) {
				if (s[i][j] == 'B') {
					two = true;
					if (i == r-1 || j == c-1)
						one = true;
					if (i == r-1 && j == c-1)
						zero = true;
				}
			}
		}
		if (zero)
			cout << "0\n";
		else if (one)
			cout << "1\n";
		else if (two)
			cout << "2\n";
		else
			cout << "-1\n";
	}
}
