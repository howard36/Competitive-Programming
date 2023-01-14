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

int a[50];

int main() { FAST
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	for (int i = 0; i<n; i++) 
		a[s[i]-'a'] = 1;
	int used = 0, last = -2, ans = 0;
	for (int i = 0; i<26; i++) {
		if (a[i] && i > last+1) {
			used++;
			last = i;
			ans += i+1;
		}
		if (used == k)
			break;
	}
	if (used == k)
		cout << ans << endl;
	else
		cout << "-1\n";
}
