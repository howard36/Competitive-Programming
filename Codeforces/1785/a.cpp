#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()
#define sz(v) (int)v.size()

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

int a[200005];

ll solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a+n);
    ll ans = 0;
    for (int idx = 0, h = 1; idx < n; h++) {
        if (a[idx] > h) {
            ans += a[idx] - h;
            idx++;
        } else {
            while (idx < n && a[idx] == h) {
                idx++;
            }
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
