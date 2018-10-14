#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100005];
int s[100005];
int dist1[100005], dist2[100005];
queue<int> q1;

int main() {
    int n, m, k, a, b;
    scanf("%d %d %d %d %d", &n, &m, &k, &a, &b);
    for (int i = 0; i<k; i++){
        scanf("%d", &s[i]);
    }
    int aa, bb;
    for (int i = 0; i<m; i++){
        scanf("%d %d", &aa, &bb);
        adj[aa].push_back(bb);
        adj[bb].push_back(aa);
    }
    for (int i = 1; i<=n; i++){
        dist1[i] = 1e9;
        dist2[i] = 1e9;
    }
    dist1[a] = 0;
    dist2[b] = 0;

    q1.push(a);
    while (!q1.empty()){
        int v = q1.front();
        q1.pop();
        for (int u : adj[v]){
            if (dist1[u] == 1e9){
                dist1[u] = dist1[v] + 1;
                q1.push(u);
            }
        }
    }
    q1.push(b);
    while (!q1.empty()){
        int v = q1.front();
        q1.pop();
        for (int u : adj[v]){
            if (dist2[u] == 1e9){
                dist2[u] = dist2[v] + 1;
                q1.push(u);
            }
        }
    }
    int best = 1e9;
    for (int i = 0; i<k; i++){
        best = min(best, dist1[s[i]] + dist2[s[i]]);
    }
    printf("%d", best);
}