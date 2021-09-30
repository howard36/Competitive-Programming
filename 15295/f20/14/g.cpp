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
typedef pair<ll,ll> pi;
typedef pair<ld,ld> pd;
typedef complex<ld> cd;

#define MOD 1000000007LL

map<ll, ll> dp, bot;
pi pos[100005];

ll h(ll x, ll y) {
    return 1000000*x+y;
}


int main() { FAST
    ll n, x, y;
    cin >> n;
    for (int i = 0; i<n; i++) {
        cin >> x >> y;
        pos[i] = pi(x,y);
    }
    sort(pos, pos+n);
    dp[h(1,1)] = 1;
    for (int i = 1; i<n; i++) {
        x = pos[i].f, y = pos[i].s;
        dp[h(x,y)] = (dp[h(x-1,y)] + dp[h(x,y-1)])%MOD;
        bot[h(x-1,y)] = 1, bot[h(x,y-1)] = 1;
    }
    ll ans = 0;
    for (int i = 0; i<n; i++) {
        x = pos[i].f, y = pos[i].s;
        if (!bot[h(x,y)])
            ans = (ans + dp[h(x,y)])%MOD;
    }
    cout << ans << endl;
}

