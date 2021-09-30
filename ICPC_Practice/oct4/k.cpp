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
typedef pair<ld,ld> pd;
typedef complex<ld> cd;

ll d1[10004];
pl ord[10004];

int main() { FAST
    ll n, m, a, b;
    cin >> n >> m;
    M00(i, m) {
        cin >> a >> b;
        d1[a]++, d1[b]++;
    }
    M00(i, n)
        ord[i] = mp(d1[i], i);
    sort(ord, ord+n);
    ll ans = 0;
    ll sum = 2*m;
    while (sum > 2*(n-1)) {
        ans++;
        ll diff = min(ord[n-ans].f-1, sum-2*(n-1));
        ord[n-ans].f -= diff;
        sum -= diff;
    }
    cout << ans << endl;
    cout << n << " " << n-1 << endl;
    sort(ord, ord+n);
    ll r = 0;
    while (ord[r].f == 1 && r < n-1)
        r++;
    M00(i, n-1) {
        cout << ord[i].s << " " << ord[r].s << endl;
        ord[r].f--;
        if (ord[r].f == 1 && r < n-1)
            r++;
    }
}
