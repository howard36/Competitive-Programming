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

ll a[100005], b[100005];

int main() { FAST
    ll n, m;
    cin >> n >> m;
    M00(i, n) cin >> a[i];
    M00(i, m) cin >> b[i];
    sort(a, a+n);
    sort(b, b+m);
    ll lo = 0, hi = 1e10;
    while (lo < hi) {
        ll mid = (lo + hi)/2;
        ll i1 = upper_bound(a, a+n, mid) - a;
        ll i2 = m - (upper_bound(b, b+m, mid) - b);
        if (i1 < i2)
            lo = mid+1;
        else
            hi = mid;
    }
    ll ans = 0;
    M00(i, n) {
        if (a[i] < lo)
            ans += lo - a[i];
    }
    M00(i, m) {
        if (b[i] > lo)
            ans += b[i] - lo;
    }
    cout << ans << endl;
}
