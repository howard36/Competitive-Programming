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
typedef pair<ld,ld> pd;
typedef complex<ld> cd;
typedef pair<ld, pi> pt;
 
const ld PI = acosl((ld)(-1));
const ld EPS = 1e-6;
 
pt a[100005];
 
void out(int l, int r) {
    for (int i = l; i<r; i++) {
        cout << a[i].s.f << " " << a[i].s.s << "\n";
    }
}
 
int main() { FAST
    int n, w, h;
    while (true) {
        cin >> n >> w >> h;
        cd center = cd(w,h)/(ld)2;
        if (n == 0)
            break;
        for (int i = 0; i<n; i++) {
            int x,y;
            cin >> x >> y;
            a[i] = pt(arg(cd(x,y) - center), pi(x,y));
        }
        sort(a, a+n);
        for (int i = 0; i<n; i++)
            a[i+n] = pt(a[i].f + 2*PI, a[i].s);
        int l = 0, r = 0;
        for (int l = 0; l<n; l++) {
            int r = 0;
            while (a[r].f < a[l].f + PI - EPS) {
                r++;
            }
            if (r-l == n/2) {
                out(l,r);
                break;
            }
            bool done = false;
            while (a[r].f <= a[l].f + PI + EPS) {
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
