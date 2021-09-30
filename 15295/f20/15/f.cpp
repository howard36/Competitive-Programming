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
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
typedef complex<ld> cd;

struct convexHull {
    set<pair<ld,ld>> dupChecker;
    vector<pair<ld,ld>> points;
    vector<pair<ld,ld>> dn, up, hull;
    
    convexHull() {}
    bool cw(pd o, pd a, pd b) {
        return ((a.f-o.f)*(b.s-o.s)-(a.s-o.s)*(b.f-o.f) <= 0);
    }
    void addPoint(pair<ld,ld> p) {
        if(dupChecker.count(p)) return;
        points.pb(p);
        dupChecker.insert(p);
    }
    void addPoint(ld x, ld y) {
        addPoint(mp(x,y));
    }
    void build() {
        sort(points.begin(), points.end());
        if(sz(points) < 3) {
            for(pair<ld,ld> p: points) {
                dn.pb(p);
                hull.pb(p);
            }
            M00d(i, sz(points)) {
                up.pb(points[i]);
            }
        } else {
            for(int i = 0; i < (int)points.size(); i++) {
                while(dn.size() >= 2 && cw(dn[dn.size()-2], dn[dn.size()-1], points[i])) {
                    dn.erase(dn.end()-1);
                }
                dn.push_back(points[i]);
            }
            for(int i = (int)points.size()-1; i >= 0; i--) {
                while(up.size() >= 2 && cw(up[up.size()-2], up[up.size()-1], points[i])) {
                    up.erase(up.end()-1);
                }
                up.push_back(points[i]);
            }
            sort(dn.begin(), dn.end());
            sort(up.begin(), up.end());
            
            for(int i = 0; i < up.size()-1; i++) hull.pb(up[i]);
            for(int i = sz(dn)-1; i > 0; i--) hull.pb(dn[i]);
        }
    }
};

ld dist(pl b, pl c) {
    return sqrtl((b.f-c.f)*(b.f-c.f) + (b.s-c.s)*(b.s-c.s));
}

pl a[10];

int main() { FAST
	ll n, d;
    cin >> n >> d;
    convexHull C = convexHull();
    /*
    ll mx = 1e18;
    ll my = 1e18;
    ll ms = 1e18;
    ll md = 1e18;
    ll Mx = -1e18;
    ll My = -1e18;
    ll Ms = -1e18;
    ll Md = -1e18;*/
    for (int i = 0; i<n; i++) {
        ll x,y;
        cin >> x >> y;
        C.addPoint(x+d,y);
        C.addPoint(x-d,y);
        C.addPoint(x,y+d);
        C.addPoint(x,y-d);
        /*
        mx = min(mx,x);
        my = min(my,y);
        ms = min(ms,x+y);
        md = min(md,x-y);
        Mx = max(Mx,x);
        My = max(My,y);
        Ms = max(Ms,x+y);
        Md = max(Md,x-y);*/
    }
    /*
    mx -= d;
    my -= d;
    ms -= d;
    md -= d;
    Mx += d;
    My += d;
    Ms += d;
    Md += d;
    a[0] = pl(Ms-My, My);
    a[1] = pl(Mx, Ms-Mx);
    a[2] = pl(Mx, Mx-Md);
    a[3] = pl(Md+my, my);
    a[4] = pl(ms-my, my);
    a[5] = pl(mx, ms-mx);
    a[6] = pl(mx, mx-md);
    a[7] = pl(md+My, My);
    a[8] = a[0];*/
    C.build();
    C.hull.pb(C.hull[0]);
    ld ans = 0;
    for (int i = 0; i<C.hull.size()-1; i++) {
        // dbg(i _ C.hull[i].f _ C.hull[i].s);
        ans += dist(C.hull[i], C.hull[i+1]);
    }
    cout << fixed << setprecision(10) << ans << "\n";
}
