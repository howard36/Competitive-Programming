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

const ll MOD = 998244353LL;

ll a[5][100005];

int main() { FAST
    ll n;
    cin >> n;

    vi nums;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            a[i][j] = 5 * a[i][j] + i;
            nums.pb(a[i][j]);
        }
    }
    
    sort(all(nums));

    ll ans = 0;
    for (ll i = 0; i < 5*n; i++) {
        ll r = 5*n - 1 - i;
        ll l2 = (i * (i-1) / 2) % MOD;
        ll r2 = (r * (r-1) / 2) % MOD;
        dbg(i _ r _ l2 _ r2 _ (nums[i] / 5))
        ans = (ans + (l2 * r2 % MOD) * (nums[i] / 5) % MOD) % MOD;
    }
    cout << ans;
}
