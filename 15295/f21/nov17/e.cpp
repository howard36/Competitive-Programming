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

int minp[1000006];

/*
perfect:
6
28
496
8128

abundant:

*/

int main() { FAST
	for (int i = 1; i<1000006; i++)
		minp[i] = i;
	for (ll i = 2; i<1000006; i++) {
		if (minp[i] == i) {
			for (ll j = i*i; j<1000006; j+=i) {
				if (minp[j] == j) {
					minp[j] = i;
				}
			}
		}
	}
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int N = n;
		int divsum = 1, p = 1, sum = 1;
		while (n > 1) {
			if (minp[n] != p) {
				divsum *= sum;
				p = minp[n];
				sum = 1;
			}
			n /= p;
			sum = p*sum + 1;
		}
		divsum *= sum;
		if (divsum > 2*N) {
			cout << "abundant\n";
		}
		else if (divsum == 2*N) {
			cout << "perfect\n";
		}
		else {
			cout << "deficient\n";
		}
	}
}
