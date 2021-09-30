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

ll s[3], dp[1000006];
ll h, bw, tw;

ll slicee(ll i) {
    return (bw*(h-i) + tw*i)/h;
}

int main() { FAST
    while (cin >> h) {
        cin >> bw >> tw;
        for (int i = 0; i<3; i++) {
            cin >> s[i];
        }
        if (h == 0) {
            cout << 0 << "\n";
            break;
        }
        dp[0] = 0;
        for (int i = 1; i<=h; i++) {
            dp[i] = -1;
        }
        ll ans = 0;
        for (int i = 1; i<=h; i++) {
            ll slice1 = slicee(i);
            for (int j = 0; j<3; j++) {
                if (s[j] == 0)
                    continue;
                if (i-s[j] >= 0 && dp[i-s[j]] != -1) {
                    ll slice2 = slicee(i-s[j]);
                    ll num = min(slice1/s[j], slice2/s[j]);
                    if (num > 0) 
                        dp[i] = max(dp[i], dp[i-s[j]] + num*num*s[j]*s[j]*s[j]);
                }
            }
            ans = max(ans, dp[i]);
        }
        cout << ans << "\n";
    }
}
