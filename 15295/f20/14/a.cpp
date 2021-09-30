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

int a[100005], b[100005], c[100005], sz[100005], p[100005];

int find(int x) {
    if (x == p[x]) return x;
    return p[x] = find(p[x]);
}

void join(int x, int y) {
    x = find(x), y = find(y);
    if (sz[x] < sz[y])
        swap(x,y);
    sz[x] += sz[y];
    p[y] = x;
}

int main() { FAST
	int n, m, x, y, sum = 0;
    cin >> n;
    for (int i = 0; i<n; i++) {
        p[i] = i;
        sz[i] = 1;
    }
    for (int i = 0; i<n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    cin >> m;
    for (int i = 0; i<m; i++) {
        cin >> x >> y;
        b[x-1] = 1, b[y-1] = 1;
        join(x-1,y-1);
    }
    bool good = true;
    for (int i = 0; i<n; i++) {
        if (a[i] && !b[i])
            good = false;
    }
    for (int i=0; i<n; i++) {
        c[find(i)] += a[i];
    }
    for (int i = 0; i<n; i++) {
        if (c[i] % 2)
            good = false;
    }
    if (good) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

