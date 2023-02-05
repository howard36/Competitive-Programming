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

int a[200005], vis[200005];
vi cycles;

int dfs(int i, int d) {
    vis[i] = 1;
    if (vis[a[i]]) return d;
    else return dfs(a[i], d+1);
}

int solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        vis[i] = 0;
    }
    cycles.clear();

    unordered_map<int, int> hm;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            int len = dfs(i, 1);
            hm[len]++;
        }
    }

    int ans = 0;
    for (pi p : hm) {
        int val = p.f;
        int freq = p.s;
        dbg(val _ freq)
        if (val % 2 == 0) {
            if (k < 30 && freq % (1<<k) == 0) {
                for (int i = 0; i < (freq>>k); i++) {
                    ans++;
                    cycles.pb(val<<k);
                }
            } else
                return -1;
        } else {
            for (int i = 0; i < k; i++) {
                if (freq % 2 == 1) {
                    ans++;
                    cycles.pb(val<<i);
                }
                freq /= 2;
                if (freq == 0)
                    break;
            }
            for (int i = 0; i < freq; i++) {
                ans++;
                cycles.pb(val<<k);
            }
        }
    }
    return 0;
}

int main() { FAST
    int t = 1;
    cin >> t;
    while (t--) {
        int res = solve();
        if (res == -1) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            int idx = 1;
            for (int j = 0; j < sz(cycles); j++) {
                int l = cycles[j];
                for (int i = 1; i < l; i++) {
                    cout << idx + i << " ";
                }
                cout << idx;
                if (j < sz(cycles) - 1)
                    cout << " ";
                idx += l;
            }
            cout << endl;
        }
    }
}
