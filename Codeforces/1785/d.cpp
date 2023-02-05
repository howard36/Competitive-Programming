#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()
#define sz(v) (int)v.size()

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

const ll MOD = 998244353LL;


template<class T> struct modular {
	T val; 
	explicit operator T() const { return val; }
	modular() { val = 0; }
	modular(const ll& v) { 
		val = (-MOD <= v && v <= MOD) ? v : v % MOD;
		if (val < 0) val += MOD;
	}
	
	// friend ostream& operator<<(ostream& os, const modular& a) { return os << a.val; }
	friend void pr(const modular& a) { pr(a.val); }
	// friend void re(modular& a) { ll x; re(x); a = modular(x); }
   
	friend bool operator==(const modular& a, const modular& b) { return a.val == b.val; }
	friend bool operator!=(const modular& a, const modular& b) { return !(a == b); }
	friend bool operator<(const modular& a, const modular& b) { return a.val < b.val; }

	modular operator-() const { return modular(-val); }
	modular& operator+=(const modular& m) { if ((val += m.val) >= MOD) val -= MOD; return *this; }
	modular& operator-=(const modular& m) { if ((val -= m.val) < 0) val += MOD; return *this; }
	modular& operator*=(const modular& m) { val = (ll)val*m.val%MOD; return *this; }
	friend modular pow(modular a, ll p) {
		modular ans = 1; for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans;
	}
	friend modular inv(const modular& a) { 
		assert(a != 0); return pow(a,MOD-2); 
	}
	modular& operator/=(const modular& m) { return (*this) *= inv(m); }
	
	friend modular operator+(modular a, const modular& b) { return a += b; }
	friend modular operator-(modular a, const modular& b) { return a -= b; }
	friend modular operator*(modular a, const modular& b) { return a *= b; }
	
	friend modular operator/(modular a, const modular& b) { return a /= b; }
};

typedef modular<int> mi;
typedef pair<mi,mi> pmi;
typedef vector<mi> vmi;
typedef vector<pmi> vpmi;

vmi fact(1, 1);
vmi inv_fact(1, 1);

mi C(int n, int k) {
  if (k < 0 || k > n) {
    return 0;
  }
  while ((int) fact.size() < n + 1) {
    fact.push_back(fact.back() * (int) fact.size());
    inv_fact.push_back(1 / fact.back());
  }
  return fact[n] * inv_fact[k] * inv_fact[n - k];
}

mi dp[20][1<<20];
mi tmp[1<<20];

void solve() {
    int n;
    cin >> n;
    int N = 1<<n;
    dp[0][0] = 0;
    for (int i = 1; i < N; i++) dp[0][i] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < N; j++) {
            int a = (1<<n) - 1 - j - (1<<(n-i-1));
            int b = (1<<(n-i-1)) - 1;
            tmp[j] = dp[i-1][j] * C(a, b);
            dbg(i _ j _ tmp[j].val _ dp[i-1][j].val _ a _ b)
        }
        dp[i][0] = 0;
        for (int j = 1; j <= N; j++) {
            dp[i][j] = dp[i][j-1] + tmp[j-1];
        }
    }
    mi mult = 1<<n;
      while ((int) fact.size() <= N/2) {
        fact.push_back(fact.back() * (int) fact.size());
      }
    for (int i = 0; i < n; i++) {
        mult *= fact[1<<i];
    }
    for (int i = 0; i < N; i++) {
        cout << (dp[n-1][i] * mult).val << endl;
    }
}

int main() { FAST
    int t = 1;
    // cin >> t;
    while (t--) {
        // cout << solve() << endl;
        solve();
    }
}
