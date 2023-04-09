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

vi adj[1503], vals[1503];
int dist[1503];

void bfs(int root) {
    dist[root] = 1;
    queue<int> q;
    q.push(root);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : adj[v]) {
            if (dist[u] == -1) {
                dist[u] = dist[v] + 1;
                q.push(u);
            }
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        vals[i].clear();
        dist[i] = -1;
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[b].pb(a);
    }

    bfs(1);

    for (int i = 1; i <= n; i++) {
        if (dist[i] == -1) {
            cout << "INFINITE" << endl;
            return;
        }
    }

    int md = 0, len = 0;
    for (int i = 1; i <= n; i++) {
        md = max(md, dist[i]);
        len += dist[i];
        vals[dist[i]].pb(i);
    }

    cout << "FINITE" << endl;
    cout << len << endl;
    for (int i = md; i > 0; i--) {
        for (int j = i; j <= md; j++) {
            for (int v : vals[j]) {
                cout << v << " ";
            }
        }
    }
    cout << endl;
}

int main() { FAST
    int t = 1;
    cin >> t;
    while (t--) {
        // cout << solve() << endl;
        solve();
    }
}
