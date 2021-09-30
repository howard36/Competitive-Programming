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

ld a[300005];

int main() { FAST
	int n;
    ld v, u;
    cin >> n >> v >> u;
    for (int i = 0; i<n; i++) {
        cin >> a[i];
    }
    sort(a, a+n);
    reverse(a, a+n);
    ld t = 0;
    for (int i = 0; i<n; i++) {
        ld t2 = t + (ld)(a[i]-a[i+1])*(i+1)/u;
        // dbg(i _ t _ t2);
        if (v*t2 >= a[i+1]) {
            ld num = a[i] - v*t;
            ld den = v + u/(i+1);
            ld ans = u*(t + num/den);
            // dbg(num _ den _ ans);
            cout << fixed << setprecision(10) << ans << "\n";
            return 0;
        }
        t = t2;
    }
}
