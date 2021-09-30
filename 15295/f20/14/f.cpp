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

int a[50][50], b[50][50], c[50];
vector<int> b2[50];
vector<pi> s[50];
int n, m, ms = 0;

bool inall(pi p) {
    for (int j = 0; j<n; j++) {
        if (c[j]) {
            bool contains = false;
            for (pi q : s[j]){
                if (p == q)
                    contains = true;
            }
            if (!contains)
                return false;
        }
    }
    return true;
}

int main() { FAST
    cin >> n >> m;
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<m; j++) {
            cin >> a[i][j];
            a[i][j]--;
            if (a[i][j] == j) {
                b[i][j] = 0;
            }
            else {
                b[i][j] = 1;
                b2[i].pb(j);
            }
            c[i] += b[i][j];
        }
        if (c[i] > 4) {
            finish("NO");
        }
        if (c[i] == 4) {
            if (a[i][a[i][b2[i][0]]] != b2[i][0]) {
                finish("NO");
            }
            else {
                int x = b2[i][0];
                int y = a[i][x];
                int z;
                if (y == b2[i][1])
                    z = 2;
                else
                    z = 1;
                int w = a[i][z];
                s[i].pb(pi(x,y));
                s[i].pb(pi(z,w));
            }
        }
        if (c[i] == 3) {
            int x = b2[i][0];
            int y = b2[i][1];
            int z = b2[i][2];
            s[i].pb(pi(x,y));
            s[i].pb(pi(x,z));
            s[i].pb(pi(y,z));
        }
        if (c[i] == 2) {
            s[i].pb(pi(b2[i][0], b2[i][1]));
        }
        ms = max(ms, (int)(s[i].size()));
    }
    if (ms == 0 || ms == 1) {
        finish("YES");
    }
    for (int i = 0; i<n; i++) {
        if (c[i]) {
            for (pi p : s[i]) {
                if (inall(p)) {
                    finish("YES");
                }
            }
            finish("NO");
        }
    }
}

