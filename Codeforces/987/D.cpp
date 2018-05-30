#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> adj[100105], dists[100105];
bool visited[100105];
int dist[100105];
queue<int> q;
int n, m, s, k;

void bfs(int g){
    memset(visited, 0, sizeof visited);
    for (int i = 1; i<=n; i++){
        dist[i] = 1e6;
    }
    dist[n+g] = -1;
    q.push(n+g);
    while (!q.empty()){
        int v = q.front();
        q.pop();
        // printf("g = %d, v = %d\n", g, v);
        for (int u : adj[v]){
            if (!visited[u]){
                if (dist[v]+1 < dist[u]){
                    dist[u] = dist[v]+1;
                    q.push(u);
                }
            }
        }
        visited[v] = true;
    }
    for (int i = 1; i <= n; i++){
        // printf("g = %d, dist[%d] = %d\n", g, i, dist[i]);
        dists[i].push_back(dist[i]);
    }
}

int main() {
    freopen("data.txt", "r", stdin);
    scanf("%d%d%d%d", &n, &m, &k, &s);
    for (int i = 1; i<=n; i++){
        int a;
        scanf("%d", &a);
        adj[n+a].push_back(i);
    }
    for (int i = 0; i<m; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i<= k; i++){
        bfs(i);
    }
    for (int i = 1; i<=n; i++){
        sort(dists[i].begin(), dists[i].end());
        ll sum = 0;
        for (int j = 0; j<s; j++){
            sum += dists[i][j];
        }
        printf("%lld ", sum);
    }
}
