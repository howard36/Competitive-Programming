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

set<pl> s[2];
ll a[1003][1003], sum[2][1003], d[2];

int main() { FAST
	ll n, m, k, p;
    cin >> n >> m >> k >> p;
    M00(i, n) M00(j, m) {
        cin >> a[i][j];
        sum[0][i] += a[i][j];
        sum[1][j] += a[i][j];
    }
    M00(i, n) s[0].insert(mp(sum[0][i], i));
    M00(i, m) s[1].insert(mp(sum[1][i], i));
    ll ans = 0;
    while (k--) {
        pl p0 = *s[0].rbegin();
        pl p1 = *s[1].rbegin();
        if (p0.f - p*d[0] > p1.f - p*d[1]) {
            ans += p0.f - p*d[0];
            d[1]++;
            s[0].erase(p0);
            s[0].insert(mp(p0.f-m*p, p0.s));
        }
        else {
            ans += p1.f - p*d[1];
            d[0]++;
            s[1].erase(p1);
            s[1].insert(mp(p1.f-n*p, p1.s));
        }
    }
    cout << ans << endl;
}
