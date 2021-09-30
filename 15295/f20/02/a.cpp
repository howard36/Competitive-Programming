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

int f[100005];

int main() { FAST
	int n, m;
    cin >> n >> m;
    int zeros = n;
    while (m--) {
        int v;
        cin >> v;
        if (f[v] == 0)
            zeros--;
        f[v]++;
        int ans = 0;
        if (zeros == 0) {
            MOO(i, 1, n+1) {
                f[i]--;
                if (f[i] == 0)
                    zeros++;
            }
            ans++;
        }
        cout << ans;
    }
}
