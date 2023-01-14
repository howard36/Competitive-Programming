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

int a[100005], mono[100005], seen[100005], bit[100005];
ll ans[100005];
int n;

void upd(int i) {
	for (; i<=n; i+=i&-i)
		bit[i]++;
}

int query(int i) {
	int ret = 0;
	for (; i>0; i-=i&-i)
		ret += bit[i];
	return ret;
}

int main() { FAST
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i<n; i++)
			cin >> a[i];
		int m = a[0], eq = 1, extra = 0;
		for (int i = 1; i<n; i++) {
			if (a[i] > m) {
				mono[i] = mono[i-1] + eq+1+extra;
				m = a[i];
				eq = 1;
				extra = 0;
			} else {
				mono[i] = mono[i-1];
				if (a[i] == m)
					eq++;
				else if (eq > 1)
					extra++;
			}
			dbg(i _ mono[i])
		}
		for (int i = 1; i<=n; i++) {
			seen[i] = 0;
			bit[i] = 0;
		}
		ll last = 0;
		for (int i = 0; i<n; i++) {
			if (!seen[a[i]]) {
				upd(n+1-a[i]);
				seen[a[i]] = 1;
			}
			ans[i] = last + query(n-a[i]);
			last = ans[i];
			dbg(i _ ans[i])
			cout << ans[i] + mono[i];
			if (i < n-1)
				cout << " ";
		}
		cout << endl;
	}
}
