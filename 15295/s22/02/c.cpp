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

int buy[100005], sell[100005];

int main() { FAST
	int n, s;
	cin >> n >> s;
	for (int i = 0; i<n; i++) {
		char d;
		int p, q;
		cin >> d >> p >> q;
		if (d == 'B') {
			buy[p] += q;
		} else {
			sell[p] += q;
		}
	}
	int bought = 0, sold = 0;
	int i;
	for (i = 0; i <= 1e5; i++) {
		if (sell[i])
			sold++;
		if (sold == s)
			break;
	}
	for (; i >= 0; i--) {
		if (sell[i]) 
			printf("S %d %d\n", i, sell[i]);
	}

	for (i = 1e5; i >= 0; i--) {
		if (buy[i]) {
			printf("B %d %d\n", i, buy[i]);
			bought++;
		}
		if (bought == s)
			break;
	}
}
