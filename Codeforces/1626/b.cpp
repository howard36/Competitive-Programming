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

int a[200005];

int main() { FAST
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int n = s.length();
		for (int i = 0; i<n; i++)
			a[i] = s[i]-'0';
		int best = 1;
		for (int i = n-1; i>0; i--) {
			if (a[i] + a[i-1] >= 10) {
				best = i;
				break;
			}
		}
		for (int i = 0; i<best-1; i++)
			cout << a[i];
		cout << a[best-1] + a[best];
		for (int i = best+1; i<n; i++)
			cout << a[i];
		cout << endl;
	}
}
