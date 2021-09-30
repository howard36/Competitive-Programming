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

#define MOD 998244353LL
ll dp[2000006], f[2000006], g[2000006];

int main() { FAST
	int n;
    cin >> n;
    dp[1] = 1;
    f[1] = 1;
    g[2] = 1;
    for (int k = 1; k<20; k++) {
        for (int i2 = 0; i2 < (1<<k); i2++) {
            int i = (1 << k) + i2;
            dp[i] = ((g[i] - f[i2] + 1) % MOD + MOD) % MOD;
            g[i+1] = (g[i] + dp[i]) % MOD;
        }
        for (int i2 = 0; i2 < (1<<k); i2++) {
            int i = (1 << k) + i2;
            f[i] = (g[1<<(k+1)] - g[1<<k] + f[i2]) % MOD;
        }
    }
    cout << g[n+1] << endl;
}
