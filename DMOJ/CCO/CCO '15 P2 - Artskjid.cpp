#include <bits/stdc++.h>
using namespace std;
#define pi pair<int, int>

vector<pi> adj[20];
int n, m, M = 0;

void dfs(int v, int d, int mask){
    if (v == n-1) {
        M = max(M, d);
        return;
    }
    for (pi p : adj[v]){
        if (((mask>>p.first)&1) == 0){
            dfs(p.first, d+p.second, mask|(1<<p.first));
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i<m; i++){
        int s, d, l;
        scanf("%d %d %d", &s, &d, &l);
        adj[s].push_back(pi(d, l));
    }
    dfs(0, 0, 1);
    printf("%d\n", M);
}