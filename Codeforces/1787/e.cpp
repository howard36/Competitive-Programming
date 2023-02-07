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

void solve() {
    int n, k, x;
    cin >> n >> k >> x;

    int xorsum = 0;
    for (int i = 0; i <= n; i++) xorsum ^= i;
    for (int i = 0; i < k; i++) xorsum ^= x;
    if (xorsum) {
        cout << "NO" << endl;
        return;
    }

    vector<vi> ans;
    vi unpaired;
    for (int i = 0; i <= n; i++) {
        if ((i^x) > n) {
            if (i) unpaired.pb(i);
        } else if (i < (i^x)) {
            vi v;
            if (i) v.pb(i);
            v.pb(i^x);
            ans.pb(v);
        }
    }

    if (sz(ans) < k) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;

    int rem = n;
    for (int i = 0; i < k-1; i++) {
        cout << sz(ans[i]) << " ";
        rem -= sz(ans[i]);
        for (int j : ans[i])
            cout << j << " ";
        cout << endl;
    }

    cout << rem << " ";
    for (int i = k-1; i < sz(ans); i++) {
        for (int j : ans[i])
            cout << j << " ";
    }
    for (int j : unpaired)
        cout << j << " ";
    cout << endl;
}

int main() { FAST
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
