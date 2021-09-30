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
#define dbg(x) 
// cerr << ">>> " << #x << " = " << x << "\n";
#define _ << " _ " <<

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ld,ld> pd;
typedef complex<ld> cd;

#define MOD 1000000007LL

ll a[1003], b[1003], p[1003];
int dp[1003][1003];

// hash of [i,j)
ll h(int i, int j) {
    return ((b[j] - p[j-i]*b[i]) % MOD + MOD) % MOD;
}

int main() { FAST
	int n;
    string s;
    cin >> n >> s;
    for (int i = 0; i<n; i++) {
        if (s[i] >= 'a' && s[i] <= 'z')
            a[i] = s[i] - 'a';
        else if (s[i] >= 'A' && s[i] <= 'Z')
            a[i] = (s[i] - 'A') + 26;
        else
            a[i] = (s[i] - '0') + 52;
    }
    p[0] = 1;
    for (int i = 1; i<=n; i++) {
        b[i] = (62*b[i-1] + a[i-1]) % MOD;
        p[i] = 62*p[i-1] % MOD;
    }

    for (int i = 0; i<n; i++) {
        dp[i][i+1] = 1;
    }
    for (int l = 2; l<=n; l++) {
        for (int i = 0; i+l<=n; i++) {
            dp[i][i+l] = 1e9;
            for (int j = i+1; j<i+l; j++) {
                dp[i][i+l] = min(dp[i][i+l], dp[i][j] + dp[j][i+l]);
            }
            ll h1 = h(i, i+l);
            for (int j = 1; j<l; j++) {
                if (l % j == 0) {
                    ll h2 = h(i, i+j);
                    if ((p[l]-1)*h2 % MOD == (p[j]-1)*h1 % MOD) {
                        dbg("match" _ i _ j _ l);
                        dp[i][i+l] = min(dp[i][i+l], dp[i][i+j]);
                    }
                }
            }
            dbg(i _ i+l _ dp[i][i+l]);
        }
    }
    dbg(h(0,1));
    dbg(h(1,2));
    dbg(h(2,3));
    dbg(h(0,2));
    dbg(h(1,3));
    finish(dp[0][n]);
}

