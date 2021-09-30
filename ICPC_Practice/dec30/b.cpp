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
typedef pair<pi,int> ppi;
typedef pair<ll,ll> pl;
typedef pair<pl,ll> ppl;
typedef pair<ld,ld> pd;
typedef complex<ld> cd;

ll x[10004], y[10004], dp[10004], tmp[10004];
const ld eps = 1e-6;

int main() { FAST
    ll n, h, a, b;
    cin >> n >> h >> a >> b;
    for (int i = 0; i<n; i++) {
        cin >> x[i] >> y[i];
    }
    dp[0] = a*(h-y[0]);
    for (int i = 1; i<n; i++) {
        dbg(i);
        for (int j = 0; j<i; j++)
            tmp[j] = 0;
        for (int j = 0; j<=i; j++) {
            ll dx = x[i] - x[j];
            ll dy = h - y[j];
            if (j == i) {
                tmp[0]++;
                int idx = lower_bound(x, x+i, x[i] - 2*dy - eps) - x;
                tmp[idx]--;
                dbg(2*x[j] - x[i]);
                dbg("rem1" _ 0 _ idx-1);
                continue;
            }
            ld rpos = dx + dy + sqrtl(dx*dy);
            ld rneg = dx + dy - sqrtl(dx*dy);
            ld xlo = x[i] - 2*rpos;
            ld xhi = x[i] - 2*rneg;
            dbg(j _ i _ xlo _ xhi _ rpos _ rneg);
            if (xlo > x[0] + eps) {
                tmp[0]++;
                int idx = lower_bound(x, x+i, xlo - eps) - x;
                tmp[idx]--;
                dbg("rem2" _ 0 _ idx-1);
            }
            if (2*dy < dx - eps) {
                int idx = upper_bound(x, x+i, xhi + eps) - x;
                tmp[idx]++;
                tmp[j+1]--;
                dbg("rem3" _ idx _ j);
            }
        }

        for (int j = 1; j<i; j++)
            tmp[j] += tmp[j-1];
        dp[i] = 1e18;
        for (int j = 0; j<i; j++) {
            if (tmp[j] == 0) {
                dbg(j _ i);
                dp[i] = min(dp[i], dp[j] + a*(h-y[i]) + b*(x[i]-x[j])*(x[i]-x[j]));
            }
        }
        dbg(i _ dp[i]);
    }
    if (dp[n-1] == 1e18)
        cout << "impossible\n";
    else
        cout << dp[n-1] << "\n";
}

