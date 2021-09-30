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
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
typedef complex<ld> cd;
typedef pair<ld, pi> pt;

const ld PI = acosl((ld)(-1));
const ld EPS = 1e-6;

pl a[100005];

void out(int l, int r) {
    for (int i = l; i<r; i++) {
        cout << a[i].f << " " << a[i].s << "\n";
    }
}

int half(pl a) {
    if (a.s > 0)
        return 0;
    if (a.s == 0 && a.f > 0)
        return 0;
    return 1;
}

bool cmp(pl a, pl b) {
    int ha = half(a), hb = half(b);
    if (ha != hb)
        return ha < hb;
    return a.s*b.f < a.f*b.s;
}

bool cmp2(int l, int r) {
    ll x1 = a[l].f, y1 = a[l].s, x2 = a[r].f, y2 = a[r].s;
    if (x1*y2 - x2*y1 != 0) 
        return x1*y2 - x2*y1 < 0;
    return x1*y1 + x2*y2 > 0;
}

bool cmp3(int l, int r) {
    ll x1 = a[l].f, y1 = a[l].s, x2 = a[r].f, y2 = a[r].s;
    return (x1*y2 - x2*y1 == 0) && (x1*y1 + x2*y2 < 0);
}   

int main() { FAST
    ll n, w, h;
	while (true) {
        cin >> n >> w >> h;
        if (n == 0)
            break;
        for (int i = 0; i<n; i++) {
            ll x,y;
            cin >> x >> y;
            a[i] = pl(2*x-w, 2*y-h);
        }
        sort(a, a+n, cmp);
        for (int i = 0; i<n; i++)
            a[i+n] = a[i];
        int l = 0, r = 0;
        for (int l = 0; l<n; l++) {
            int r = 0;
            while (cmp2(l, r)) {
                r++;
            }
            if (r-l == n/2) {
                out(l,r);
                break;
            }
            bool done = false;
            while (cmp3(l, r)) {
                r++;
                if (r-l == n/2) {
                    out(l,r);
                    done = true;
                    break;
                }
            }
            if (done)
                break;
        }
    }
}
