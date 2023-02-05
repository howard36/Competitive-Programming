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

int a[200005], eend[200005], reach[200005], vis[200005], rev_reach[200005];
int n;
vi rev[200005];

void path(int i) {
    vis[i] = 1;
    int j = i + a[i];
    if (j < 0 || j >= n) {
        eend[i] = 1;
    } else {
        rev[j].pb(i);
        if (reach[i])
            reach[j] = reach[i] + 1;
        if (!vis[j])
            path(j);
        if (eend[j] == -1) // loop
            eend[i] = 0;
        else
            eend[i] = eend[j];
    }
}

void dfs(int i) {
    rev_reach[i] = 1;
    for (int j : rev[i]) {
        if (rev_reach[j] == -1)
            dfs(j);
        rev_reach[i] += rev_reach[j];
    }
}

ll solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        eend[i] = -1;
        reach[i] = 0;
        vis[i] = 0;
        rev[i].clear();
        rev_reach[i] = -1;
    }
    reach[0] = 1;
    int num_ends = 0;
    for (int i = 0; i < n; i++) {
        if (!vis[i])
            path(i);
        num_ends += eend[i];
    }
    if (eend[0]) {
        for (int i = 0; i < n; i++) {
            if (reach[i] && rev_reach[i] == -1)
                dfs(i);
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (reach[i]) {
            // go to out of bounds
            ans += n + 1;
            // or anything that ends (without forming a loop)
            if (eend[0])
                ans += num_ends - rev_reach[i]; // should be -rev_reachable[i]
            else
                ans += num_ends;
        } else {
            // go anywhere
            if (eend[0])
                ans += 2*n + 1;
        }
    }
    return ans;
}

bool valid2() {
    int x = 0;
    for (int i = 0; i < n; i++) {
        x += a[x];
        if (x < 0 || x >= n) return true;
    }
    return false;
}

ll solve2() {
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = -n; j <= n; j++) {
            int orig = a[i];
            a[i] = j;
            if (valid2()) ans++;
            a[i] = orig;
        }
    }
    return ans;
}

int main() { FAST
    // n = 4;
    // // a[0] = 0;
    // // a[1] = -2;
    // // cout << solve() << endl;
    // // cout << solve2() << endl;
    // // return 0;

    // int k = 2*n + 1;
    // ll mmax = 1;
    // for (int i = 0; i < n; i++) mmax *= k;
    // for (ll m = 0; m < mmax; m++) {
    //     ll mm = m;
    //     for (int i = 0; i < n; i++) {
    //         a[i] = mm % k - n;
    //         mm /= k;
    //     }
    //     ll a1 = solve();
    //     ll a2 = solve2();
    //     if (a1 != a2) {
    //         dbg(a1 _ a2 _ a[0] _ a[1] _ a[2])
    //         return 0;
    //     }
    // }
    // dbg("done")
    int t = 1;
    cin >> t;
    while (t--) {
        cout << solve() << endl;
    }
}
