#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>

vector<pll> adj[300005];
ll path[300005], dist[300005], depth[300005], parent[300005], diff[300005];
bool easy = false;
int n, m;

void dfs(int v, int p, ll d) {
    parent[v] = p;
    dist[v] = d;
    for (pll pair : adj[v]) {
        if (pair.first != p) {
            dfs(pair.first, v, d + pair.second);
            if (path[pair.first])
                path[v] = 1;
        }
    }
    if (path[v] == 1) {
        if (adj[v].size() > 3) {
            easy = true;
        }
        if ((v == 1 || v == n) && adj[v].size() > 2) {
            easy = true;
        }
        for (pll pair : adj[v]) {
            if (pair.first != p && path[pair.first] == 0) {
                if (adj[pair.first].size() > 1) {
                    easy = true;
                }
                depth[v] = pair.second;
            }
        }
    }
}

int main() {
    // freopen("data.txt", "r", stdin);
    scanf("%d %d", &n, &m);
    ll a, b, w;
    for (int i = 1; i < n; i++) {
        scanf("%lld %lld %lld", &a, &b, &w);
        adj[a].push_back(make_pair(b, w));
        adj[b].push_back(make_pair(a, w));
    }
    path[n] = 1;
    dfs(1, -1, 0);

    if (easy) {
        for (int i = 0; i < m; i++) {
            printf("%lld\n", dist[n]);
        }
        return 0;
    }

    ll maxDiff = -1e18, best = -1e18;
    for (int v = n; v != 1; v = parent[v]) {
        maxDiff = max(maxDiff, depth[v] - dist[v]);
        diff[v] = maxDiff;
    }

    int last = -1;
    for (int v = n; v != 1; v = parent[v]) {
        int u = parent[v];
        if (depth[u] == 0 && depth[v] == 0) {
            if (last != -1) {
                best = max(best, dist[u] + diff[last]);
            }
        } else {
            best = max(best, dist[u] + depth[u] + diff[v]);
        }
        last = v;
    }

    ll x;
    for (int i = 0; i < m; i++) {
        scanf("%lld", &x);
        printf("%lld\n", dist[n] + min(0LL, best + x));
    }
}