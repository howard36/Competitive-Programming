#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()
#define sz(v) (int)v.size()

#define MOO(i, a, b) for (int i=a; i<b; i++)
#define M00(i, a) for (int i=0; i<a; i++)
#define MOOd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define M00d(i,a) for (int i = (a)-1; i >= 0; i--)

#define FAST ios::sync_with_stdio(0); cin.tie(0);
#define finish(x) return cout << x << '\n', 0;
#define dbg(x) cerr << ">>> " << #x << " = " << x << "\n";
#define _<< " _ " <<

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pd;
typedef complex<ld> cd;
typedef vector<int> vi;
typedef vector<ll> vll;

typedef unsigned long long uint64;

int n;
const int x = 16;
uint64 seeds[4];
ll hashs[4][1 << x];
bool good = false;
ll seen[1 << 26];

uint64 xoroshiro128plus(uint64 s[2]) {
  uint64 s0 = s[0];
  uint64 s1 = s[1];
  uint64 result = s0 + s1;
  s1 ^= s0;
  s[0] = ((s0 << 55) | (s0 >> 9)) ^ s1 ^ (s1 << 14);
  s[1] = (s1 << 36) | (s1 >> 28);
  return result;
}
vi solve(int depth) {
	ll X = 1 << depth;
	ll mask = (1LL << n) - 1;
	M00(i, X) M00(j, X) {
		seen[i*X + j] = (hashs[0][i] ^ hashs[1][j]) & mask;
	}
	sort(seen, seen + X*X);
	M00(i, X) M00(j, X) {
		//implement binary search as well?
		ll look = mask & (hashs[2][i] ^ hashs[3][j]);
		bool found = false;
		int lo = 0, hi = X*X;
		while(lo < hi) {
			int mid = (lo+hi)/2;
			if(seen[mid] == look) {
				found = true;
				break;
			} else if(seen[mid] < look) {
				lo = mid + 1;
			} else {
				hi = mid - 1;
			}
		}

		if(found) {
			vi ans(4);
			M00(k, X) M00(l, X) {
				if((mask & (hashs[0][k] ^ hashs[0][l])) == look) {
					ans[0] = k;
					ans[1] = l;
					break;
				}
			}
			ans[2] = i;
			ans[3] = j;
			good = true;
			return ans;
		}
	}
	vi ans = {};
	return ans;
}

int main() { FAST
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	cin >> n;
	M00(i, 4) cin >> seeds[i];
	M00(i, 4) {
		uint64 state[2] = {seeds[i], seeds[i] ^ 0x7263d9bd8409f526};
		M00(j, 1 << x) {
			hashs[i][j] = xoroshiro128plus(state);
		}
	}
	dbg("rng")
	for(int i = 10;;i++) {
		dbg(i);
		vi ans = solve(i);
		if(good) {
			M00(j, 4) cout << ans[i] + 1 << " ";
			cout << endl;
			return 0;
		}
	}
}
