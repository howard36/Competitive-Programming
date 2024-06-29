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

ll a[1000006];

void solve() {
    int n, k;
    ll m;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a+n);
    ll bestval = -1;
    int bestidx = -1;
    ll t = a[k-1]-1;
    if (t >= 0) {
        int l = t, r = (a[2*k-2] - t) / 2;
        if (l + 1 + r > bestval) {
            bestval = l + 1 + r;
            bestidx = t;
        }
    }
}

int main() { FAST
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
