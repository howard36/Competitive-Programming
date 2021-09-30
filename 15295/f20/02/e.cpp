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

set<pl> S;
ll v[100005];

int main() { FAST
	ll n, m, t;
    cin >> n >> m >> t;
    string s;
    bool filled = false;
    ll ans = 0;
    M00(i, n) {
        cin >> s;
        ll a = (((s[0]-'0')*10+(s[1]-'0'))*60 + (s[3]-'0')*10+(s[4]-'0'))*60 + (s[6]-'0')*10+(s[7]-'0');
        while ((!S.empty()) && ((*S.begin()).f <= a - t))
            S.erase(S.begin());
        if (S.size() == m)
            S.erase(--(S.end()));
        else
            ans++;
        S.insert(mp(a, i));
        if (S.size() == m)
            filled = true;
        v[i] = ans;
    }
    if (!filled) {
        finish("No solution");
    }
    cout << ans << endl;
    M00(i,n)
        cout << v[i] << endl;
}
