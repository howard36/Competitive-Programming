#pragma GCC optimize("Ofast")
#pragma GCC target("sse4")

#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> adj[1000006];
set<ll> cntSet;
bool used[1000006], cnt[1000006];

inline ll h(ll a, ll b) {
    return (a << 32) + b;
}

void update(int v, int change) {
    cntSet.erase(h(cnt[v], v));
    cnt[v] += change;
    cntSet.insert(h(cnt[v], v));
    // printf("Updated %d to %d\n", v, cnt[v]);
}

void unuse(int v) {
    used[v] = false;
    update(v, -1);
    for (int &u1 : adj[v]) {
        update(u1, -1);
        for (int &u2 : adj[u1]) {
            if (u2 != v)
                update(u2, -1);
        }
    }
}

void use(int v) {
    // printf("Using %d\n", v);
    for (int &u : adj[v]) {
        if (used[u]) {
            unuse(u);
        }
    }
    used[v] = true;
    update(v, 1);
    for (int &u1 : adj[v]) {
        if (!used[u1]) {
            update(u1, 1);
            for (int &u2 : adj[u1]) {
                if (u2 != v)
                    update(u2, 1);
            }
        }
    }
}

int main() {
    // freopen("data.txt", "r", stdin);
    int n, m, a, b;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
    }
    for (int i = 1; i <= n; i++) {
        cntSet.insert(h(0, i));
    }
    while (true) {
        ll p = *cntSet.begin();
        if ((p >> 32) > 0) {
            break;
        }
        // printf("%lld\n", (int)(p % (1LL << 32)));
        use((int)(p % (1LL << 32)));
    }
    int total = 0;
    for (int i = 1; i <= n; i++) {
        if (used[i])
            total++;
    }
    printf("%d\n", total);
    for (int i = 1; i <= n; i++) {
        if (used[i])
            printf("%d ", i);
    }
}