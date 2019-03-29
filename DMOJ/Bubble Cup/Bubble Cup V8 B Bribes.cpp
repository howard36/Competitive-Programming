#include <bits/stdc++.h>
#define pi pair<int, int>
using namespace std;

// upedge[ch] = 1 means ch -> par, 0 means ch <-> par, -1 means par -> ch
int e[100005][3], depth[100005], par[100005], upedge[100005], pos[100005];
vector<pi> adj[100005];
vector<int> tour;

void dfs(int v, int p, int d){
    pos[v] = tour.size();
    tour.push_back(v);
    par[v] = p;
    depth[v] = d;
    for (pi ch : adj[v]){
        if (ch.first != p){
            upedge[ch.first] = ch.second;
            dfs(ch.first, v, d+1);
            tour.push_back(v);
        }
    }
}

int main() {
    int n, k, a, b, c;
    scanf("%d", &n);
    for (int i = 0; i<n-1; i++){
        scanf("%d %d %d", &a, &b, &c);
        adj[a].push_back(pi(b, -c));
        adj[b].push_back(pi(a, c));
    }
    dfs(1, 0, 0);
}