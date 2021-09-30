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

#define mod 998244353LL

int main() { FAST
	ll n, k;
	cin >> n >> k;
	ll last = -1, ans = 1, a;
	for (int i = 0; i<n; i++) {
		cin >> a;
		if (a > n-k) {
			if (last != -1) 
				ans = ans*(i - last)%mod;
			last = i;
		}
	}
	cout << n*(n+1)/2 - (n-k)*(n-k+1)/2 << " " << ans << endl;
	
}
