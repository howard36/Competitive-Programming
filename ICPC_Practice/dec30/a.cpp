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
typedef pair<pi,int> ppi;
typedef pair<ll,ll> pl;
typedef pair<pl,ll> ppl;
typedef pair<ld,ld> pd;
typedef complex<ld> cd;


ppi r[2][500005];
int last[2][500005], ans[2][500005];

set<pi> makeSet(int t, int i) {
    set<pi> s;
    for (int j = i; j<=last[t][i]; j++) {
        s.insert(pi(r[t][j].f.s, r[t][j].s));
    }
    return s;
}

int main() { FAST
    int n;
    cin >> n;
    for (int t = 0; t<2; t++) {
        for (int i = 0; i<n; i++)
            cin >> r[t][i].f.f;
        for (int i = 0; i<n; i++)
            cin >> r[t][i].f.s;
        for (int i = 0; i<n; i++)
            r[t][i].s = i;
    }
    sort(r[0], r[0]+n);
    sort(r[1], r[1]+n);
    for (int t = 0; t<2; t++) {
        r[t][n].f.f = 1000000001;
        for (int i = n-1; i>=0; i--) {
            if (r[t][i].f.f < r[t][i+1].f.f)
                last[t][i] = i;
            else
                last[t][i] = last[t][i+1];
        }
    }
    set<pi> s0 = makeSet(0, 0);
    set<pi> s1 = makeSet(1, 0);
    for (int i = 0; i<n; i++) {
        if (last[0][i] < last[1][i]) {
            auto it = s0.end();
            it--;
            int h = (*it).f;
            ans[0][i] = (*it).s;
            s0.erase(it);
            it = s1.lower_bound(pi(h, 0));
            if (it == s1.begin()) {
                finish("impossible");
            }
            it--;
            ans[1][i] = (*it).s;
            s1.erase(it);
        }
        else {
            int h = (*s1.begin()).f;
            ans[1][i] = (*s1.begin()).s;
            s1.erase(s1.begin());
            auto it = s0.lower_bound(pi(h+1,0));
            if (it == s0.end()) {
                finish("impossible");
            }
            ans[0][i] = (*it).s;
            s0.erase(it);
        }
        if (i < n-1 && last[0][i] == i)
            s0 = makeSet(0, i+1);
        if (i < n-1 && last[1][i] == i)
            s1 = makeSet(1, i+1);
    }
    for (int t = 0; t<2; t++) {
        for (int i = 0; i<n; i++) {
            cout << ans[t][i] + 1 << " ";
        }
        cout << "\n";
    }
}

