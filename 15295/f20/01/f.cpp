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
typedef pair<ll> pi;
typedef vector<pi> vpi;
typedef pair<ld,ld> pd;
typedef complex<ld> cd;

vpi adj[102];

bool works(ll r) {
    
}

int main() { FAST
	ll t;
    cin > t;
    while (t--) {
        ll n, k, m, a, b, w;
        cin >> n >> k >> m;
        M00(i, m) {
            cin >> a >> b >> w;
            adj[a].pb(mp(b, w));
            adj[b].pb(mp(a, w));
        }
        ll lo = 0, hi = 1e12;
        while (lo < hi) {
            ll mid = (lo+hi)/2;
            if (works(mid))
                hi = mid;
            else
                lo = mid+1;
        }
    }
}
