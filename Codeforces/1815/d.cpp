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
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
typedef complex<ld> cd;

const ll MOD = 998244353LL;

ll m;
set<ll> possible;

// for all a_b, a_(b-1), a_(b-2), ..., a_2, a_1, a_0 between 0 and m
// such that sum a_i * 2^i = n, consider the xors
// return: (# of unique xors, sum of xors)
pl rec(int b, ll n) {
    dbg(b _ n)
    ll B = 1LL << b;
    if (n < 0 || n / m > 2*B-1) {
        return pl(0, 0);
    }

    if (b == 0) {
        return pl(1, n%2);
    }

    ll ways = 0, sum_xor = 0, x = 0;
    for (int i = 0; i <= m; i++) {
        ll n1 = n - i*B;
        if (n1 < 0) {
            break;
        }
        // dbg(b _ i _ n1 _ x)
        pl p = rec(b-1, n1);
        dbg(p.f _ p.s)
        ways += p.f;
        if (p.f % 2 == 1) {
            sum_xor = (sum_xor + (p.f*x) % MOD + p.s) % MOD;
        }
        x ^= B;
        // dbg(x)
    }
    return pl(ways, sum_xor);
}

int solve() {
    possible.clear();
    ll n;
    cin >> n >> m;
    pl p = rec(60, n);
    dbg(p.f _ p.s)

    // ll ans = 0;
    // dbg(possible.size())
    // for (ll x : possible) {
    //     // dbg(x)
    //     ans = (ans + x) % MOD;
    // }

    return p.s;
}

int main() { FAST
    int t = 1;
    cin >> t;
    while (t--) {
        cout << solve() << endl;
    }
}
