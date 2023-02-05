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

ll a[200005], x[200005][2], dp[200005][2];

ll solve() {
    int n, s;
    cin >> n >> s;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] <= s) {
            x[i][0] = 0;
            x[i][1] = a[i];
        } else if (a[i] <= 2*s) {
            x[i][0] = a[i]-s;
            x[i][1] = s;
        } else {
            x[i][0] = s;
            x[i][1] = a[i]-s;
        }
    }
    dp[2][0] = a[1] * x[2][1];
    dp[2][1] = a[1] * x[2][0];
    for (int i = 3; i < n; i++) {
        for (int tx = 0; tx < 2; tx++) {
            int ty = 1-tx;
            dp[i][ty] = dp[i-1][tx] + x[i-1][tx] * x[i][tx];
            dp[i][ty] = min(dp[i][ty], dp[i-1][ty] + x[i-1][ty] * x[i][tx]);
        }
    }
    ll ans = x[n-1][1] * a[n] + dp[n-1][1];
    ans = min(ans, x[n-1][0] * a[n] + dp[n-1][0]);
    return ans;
}

int main() { FAST
    int t = 1;
    cin >> t;
    while (t--) {
        cout << solve() << endl;
    }
}
