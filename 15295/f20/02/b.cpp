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

set<pi> s[2];
multiset<int> sz[2];

int main() { FAST
    int w, h, n, v;
    char c;
    cin >> w >> h >> n;
    s[0].insert(mp(0,w));
    s[1].insert(mp(0,h));
    sz[0].insert(w);
    sz[1].insert(h);
    while (n--) {
        cin >> c >> v;
        int t = 0;
        if (c == 'H')
            t = 1;
        auto it = s[t].upper_bound(mp(v, 0));
        it--;
        pi p = *it;
        s[t].erase(it);
        s[t].insert(mp(p.f, v));
        s[t].insert(mp(v, p.s));
        sz[t].erase(sz[t].find(p.s-p.f));
        sz[t].insert(v-p.f);
        sz[t].insert(p.s-v);
        cout << 1LL * (*sz[0].rbegin()) * (*sz[1].rbegin()) << endl;
    }
}
