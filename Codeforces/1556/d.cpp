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

int q[2][10004];
int x[10004];
int a[10004];

int main() { FAST
	int n, k;
	cin >> n >> k;
	int confused = (1<<30)-1;
	for (int i = 1; i<n; i++) {
		cout << "and 1 " << i+1 << endl;
		fflush(stdout);
		cin >> q[0][i];
		cout << "or 1 " << i+1 << endl;
		fflush(stdout);
		cin >> q[1][i];
		x[i] = q[0][i] ^ q[1][i];
		confused &= x[i];
	}
	cout << "and 2 3" << endl;
	fflush(stdout);
	int first;
	cin >> first;
	first &= confused;
	first ^= confused;
	for (int i = 1; i<n; i++)
		first |= q[0][i];
	a[0] = first;
	for (int i = 1; i<n; i++)
		a[i] = first ^ x[i];
	for (int i = 0; i<n; i++)
		dbg(i _ x[i] _ a[i]);
	sort(a, a+n);
	cout << "finish " << a[k-1] << endl;
	fflush(stdout);
	return 0;
}
