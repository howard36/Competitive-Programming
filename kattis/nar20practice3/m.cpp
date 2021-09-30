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
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
typedef complex<ld> cd;

vector<pl> pts;
ll ys[100005];
map<ll,ll> comp;

ll bit[100005];

ll query(int i) {
    i++;
    ll ans = 0;
    for (; i > 0; i-=(i&-i))
        ans = max(ans, bit[i]);
    return ans;
}

void upd(int i, ll v) {
    i++;
    for (; i<100005; i+=(i&-i))
        bit[i] = max(bit[i], v);
}

int main() { FAST
	int n;
    cin >> n;
    ll xh, yh, xw, yw;
    cin >> xh >> yh >> xw >> yw;
    ll mx = min(xh,xw);
    ll Mx = max(xh,xw);
    ll my = min(yh,yw);
    ll My = max(yh,yw);
    for (int i = 0; i<n; i++) {
        ll x, y;
        cin >> x >> y;
        if (mx <= x && x <= Mx && my <= y && y <= My)
            pts.pb(pl(x,y));
    }
    n = pts.size();
    for (int i = 0; i<n; i++) {
        pts[i].f -= xh;
        pts[i].s -= yh;
    }
    xw -= xh;
    yw -= yh;
    xh = yh = 0;
    if (xw < 0) {
        for (int i = 0; i<n; i++)
            pts[i].f *= -1;
        xw *= -1;
    }
    if (yw < 0) {
        for (int i = 0; i<n; i++)
            pts[i].s *= -1;
        yw *= -1;
    }

    for (int i = 0; i<n; i++) {
        ys[i] = pts[i].s;
        dbg(pts[i].f _ pts[i].s);
    }
    ys[n] = 0;
    ys[n+1] = yw;
    sort(ys, ys+n+2);
    for (int i = 0; i<n+2; i++)
        dbg(ys[i]);
    for (int i = 0; i<n+2; i++) {
        comp[ys[i]] = i;
    }
    for (int i = 0; i<n; i++) {
        pts[i].s = comp[pts[i].s];
        dbg(pts[i].f _ pts[i].s);
    }
    yw = comp[yw];

    sort(all(pts));
    for (int i = 0; i<n; i++) {
        ll y = pts[i].s;
        upd(y, query(y) + 1);
    }
    cout << query(yw) << endl;
}
