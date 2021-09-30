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
typedef pair<pl,ll> ppl;
typedef pair<ld,ld> pd;
typedef complex<ld> cd;

#define MOD 1000000007LL

ll psa[1003], len[2503], sum[2503], val[2503];
bool concat[2503];
pl split[2503];

// substring [0, n) of S(i)
ll query(ll i, ll n) {
    if (i == 0)
        return psa[n];

    if (concat[i]) {
        ll x = split[i].f, y = split[i].s;
        if (n <= len[x])
            return query(x, n);
        else
            return (query(y, n-len[x]) + sum[x]) % MOD;
    }
    else {
        ll x = split[i].f, lo = split[i].s;
        return ((query(x, lo+n) - val[i]) % MOD + MOD) % MOD;
    }
}

int main() { FAST
    int n;
    string s;
    cin >> n >> s;
    len[0] = s.length();
    for (int i = 0; i<len[0]; i++) {
        psa[i+1] = (psa[i] + (ll)s[i]) % MOD;
    }
    sum[0] = psa[len[0]];
    for (int i = 1; i<n; i++) {
        string t;
        cin >> t;
        if (t[0] == 'A') {
            ll x, y;
            cin >> x >> y;
            concat[i] = true;
            len[i] = len[x] + len[y];
            split[i] = pl(x,y);
            sum[i] = (sum[x] + sum[y]) % MOD;
        }
        else {
            ll x, lo, hi;
            cin >> x >> lo >> hi;
            concat[i] = false;
            len[i] = hi - lo;
            split[i] = pl(x, lo);
            val[i] = query(x, lo);
            sum[i] = ((query(x, hi) - val[i]) % MOD + MOD) % MOD;
        }
    }
    finish(sum[n-1]);
}

