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

priority_queue<int, vector<int>, greater<int>> pq;
pi a[1000006];

int main() { FAST
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 0; i<n; i++) {
			int x, y;
			cin >> x >> y;
			a[i] = mp(-x, y);
		}
		sort(a, a+n);
		ll ans = 0;
		while (!pq.empty())
			pq.pop();
		int bought = 0;
		for (int i = 0; i<n; i++) {
			int x = -a[i].f, y = a[i].s;
			dbg(i _ x _ y _ bought _ n-i-1)
			pq.push(y);
			if (x > n-i-1+bought) {
				ans += pq.top();
				pq.pop();
				dbg(i _ x _ y _ ans)
				bought++;
			}
		}
		cout << ans << endl;
	}
}
