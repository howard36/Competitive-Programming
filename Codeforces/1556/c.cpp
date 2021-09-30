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

ll a[1003];

int main() { FAST
	int n;
	cin >> n;
	vector<ll> s;
	ll cur = 0;
	s.pb(cur);
	ll ans = 0;
	for (int i = 0; i<n; i++) {
		cin >> a[i];
		if (i%2 == 0) {
			cur += a[i];
			s.pb(cur);
			continue;
		}
		ll newcur = cur - a[i];
		ll top = s.back();
		s.pop_back();
		while (!s.empty()) {
			ll bot = s.back();
			dbg(top _ bot _ s.size());
			if (newcur >= bot) {
				ans += top - newcur + 1;
				dbg(i _ ans);
				if (newcur == bot) {
					for (int j = s.size()-2; j>=0; j--) {
						if (s[j] <= bot);
							ans++;
						if (s[j] < bot)
							break;
					}
				}
				dbg(i _ ans);
				break;
			}
			ans += top - bot + 1;
			top = bot;
			s.pop_back();
			dbg(i _ ans);
		}
		s.pb(newcur);
		cur = newcur;
		//dbg(i _ ans);
	}
	ans -= n/2;
	finish(ans);
}
