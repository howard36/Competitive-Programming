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
typedef pair<ll,ll> pi;
typedef pair<ld,ld> pd;
typedef complex<ld> cd;

ll A[1000006], B[1000006], S[1000006], T[1000006];
ld P[1000006];
pi ord[1000006];
set<pair<ll,ld>> dp[1000006];

int main() { FAST
    ll m, n, k, a, b, s, t;
    ld p;
    cin >> m >> n >> k;
    M00(i, m) {
        cin >> A[i] >> B[i] >> S[i] >> T[i] >> P[i];
        ord[i] = mp(-S[i], i);
    }
    sort(ord, ord+m);
    M00(i, n) {
        if (i == 1)
            dp[i].insert(mp(k+1, -1));
        else
            dp[i].insert(mp(k+1, 0));
    }
    M00(ii, m) {
        ll i = ord[ii].s;
        a = A[i], b = B[i], s = S[i], t = T[i], p = P[i];
        ld prob = p * (*dp[b].lower_bound(mp(t+1,-2))).s + (1-p) * (*dp[a].lower_bound(mp(s+1,-2))).s;
        prob = min(prob, (*dp[a].lower_bound(mp(s,-2))).s);
        dp[a].insert(mp(s, prob));
    }
    ld ans = -(*dp[0].lower_bound(mp(0,-2))).s;
    cout << fixed << setprecision(10) << ans << endl;
}
