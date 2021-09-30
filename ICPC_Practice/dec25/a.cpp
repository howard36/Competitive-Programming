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
typedef pair<pl,ll> ppl;
typedef pair<ld,ld> pd;
typedef complex<ld> cd;

ppl pts[4003], tmp[4003];

bool cmp(ppl a, ppl b) {
    if (a.f.s >= 0 && b.f.s < 0) 
        return false;
    if (a.f.s < 0 && b.f.s >= 0)
        return true;
    return a.f.f * b.f.s > a.f.s * b.f.f;
}

int main() { FAST
    int n;
    cin >> n;
    for (int i = 0; i<n; i++) {
        cin >> pts[i].f.f >> pts[i].f.s >> pts[i].s;
    }
    for (int i = 0; i<n; i++) {
        ll x = pts[i].f.f, y = pts[i].f.s;
        for (int j = 0; j<i; j++) {
            tmp[j] = ppl(pl(pts[j].f.f - x, pts[j].f.s - y), pts[j].s);
        }
        for (int j = i+1; j<n; j++) {
            tmp[j-1] = ppl(pl(pts[j].f.f - x, pts[j].f.s - y), pts[j].s);
        }
        sort(tmp, tmp+n-1, cmp);
        for (int j = 0; j<n; j++) {
            dbg(tmp[j].f.f _ tmp[j].f.s);
        }
    }
    
}

