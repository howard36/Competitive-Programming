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
#define dbg(x) // cerr << ">>> " << #x << " = " << x << "\n";
#define _ << " _ " <<

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ld,ld> pd;
typedef complex<ld> cd;

int z[2000006], d1[2000006], d2[2000006];

int solve(string s){
	int n = s.length(), l = 0, r = 0;
	for (int i = 1; i<n; i++) {
		z[i] = 0;
		if (i <= r)
			z[i] = min(z[i-l], r-i+1);
		while (i + z[i] < n && s[z[i]] == s[i+z[i]])
			z[i]++;
		if (i + z[i] - 1 > r) {
			l = i;
			r = i+z[i]-1;
		}
		if (i >= n/2 && i + z[i] == n)
			return z[i];
	}
	assert(false);
	return -1;
}

int main() { FAST
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int n = s.length();
		int idx = 0;
		while (idx < n && s[idx] == s[n-1-idx]) idx++;
		if (idx == n) {
			cout << s << endl;
			continue;
		}
		string ss = s.substr(idx, n-2*idx);
		string rev = ss;
		reverse(all(rev));
		int l1 = solve(ss + rev);
		int l2 = solve(rev + ss);
		dbg(l1 _ l2);
		if (l1 > l2)
			cout << s.substr(0, idx+l1) << s.substr(n-idx, idx) << endl;
		else
			cout << s.substr(0, idx) << s.substr(n-idx-l2, idx+l2) << endl;
	}	
}
