#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()
#define sz(v) (int)(v.size())

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

vi manacher(string s) {
	string s1 = "@";
	for (char c : s) s1 += c, s1 += '#';
	s1[sz(s1)-1] = '&';

	vi ans(sz(s1)-1);
	int lo = 0, hi = 0;
	MOO(i,1,sz(s1)-1) {
		if (i != 1) ans[i] = min(hi-i, ans[hi-i+lo]);
		while (s1[i-ans[i]-1] == s1[i+ans[i]+1]) ans[i]++;
		if (i+ans[i] > hi) lo = i-ans[i], hi = i+ans[i];
	}
	ans.erase(begin(ans));
	M00(i,sz(ans)) if ((i&1) == (ans[i]&1)) ans[i]++;
	return ans;
}

int main() { FAST
	string s;
	cin >> s;
	vi v = manacher(s);
	int n = sz(v);
	int l = -1;
	for (int i = 0; i < n; i++) {
		if (i&1) {
			if (i - v[i] <= l + 1 && i + v[i] <= n)
				l = i;
		}
	}
	int r = n;
	for (int i = n-1; i > l; i--) {
		if (i&1) {
			if (i + v[i] >= r - 1 && i - v[i] >= l)
				r = i;
		}
	}
	cout << (r - l) / 2 << "\n";
}
