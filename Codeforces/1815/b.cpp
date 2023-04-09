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

int dist(int i, int j) {
    cout << "? " << i << " " << j << endl;
    int r;
    cin >> r;
    return r;
}

int loc[1003], loc2val[1003];

void solve() {
    int n;
    cin >> n;

    int tmp;
    cout << "+ " << n << endl;
    cin >> tmp;
    cout << "+ " << n+1 << endl;
    cin >> tmp;
    loc2val[0] = n, loc2val[1] = 1;
    for (int i = 2; i < n; i+=2) {
        loc2val[i] = loc2val[i-2] - 1;
    }
    for (int i = 3; i < n; i+=2) {
        loc2val[i] = loc2val[i-2] + 1;
    }
    for (int i = 0; i < n; i++) {
        dbg(i _ loc2val[i])
    }

    int d = dist(1, 2);
    loc[1] = 0, loc[2] = d;
    
    int m = 0;
    for (int i = 3; i <= n; i++) {
        int d1 = dist(1, i);
        int d2 = dist(2, i);
        if (d1 > d && d1 > d2) {
            loc[i] = d1;
        } else if (d2 > d && d2 > d1) {
            loc[i] = d - d2;
        } else {
            loc[i] = d1;
        }
        m = min(m, loc[i]);
    }

    for (int i = 1; i <= n; i++) {
        loc[i] -= m;
        dbg(i _ loc[i])
    }

    cout << "!";
    for (int i = 1; i <= n; i++) {
        cout << " " << loc2val[loc[i]];
    }
    for (int i = 1; i <= n; i++) {
        cout << " " << loc2val[n-1-loc[i]];
    }
    cout << endl;
    cin >> tmp;
}

int main() { FAST
    int t = 1;
    cin >> t;
    while (t--) {
        // cout << solve() << endl;
        solve();
    }
}
