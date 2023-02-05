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

vector<pi> factor(int n) {
    vector<pi> v;
    for (int d = 2; d * d <= n; d++) {
        if (n % d == 0) {
            int p = 0;
            while (n % d == 0) {
                n /= d;
                p++;
            }
            v.pb(mp(p,d));
        }
    }
    if (n > 1)
        v.pb(mp(1,n));
    return v;
}

int solve() {
    int n;
    cin >> n;
    vector<pi> v = factor(n);
    sort(all(v));
    int prod = 1;
    for (pi p : v) {
        prod *= p.s;
        dbg(p.f _ p.s)
    }
    int ans = 0, h = 0, idx = 0;
    while (idx < v.size()) {
        pi p = v[idx];
        int diff = p.f - h;
        dbg(prod _ diff _ idx)
        ans += prod * diff;
        h += diff;
        while (idx < v.size() && v[idx].f == h) {
            prod /= v[idx].s;
            idx++;
            dbg(idx _ prod)
        }
    }
    return ans;
}

int main() { FAST
    int t = 1;
    cin >> t;
    while (t--) {
        cout << solve() << endl;
    }
}
