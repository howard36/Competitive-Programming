#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1000006];
double p[1000006];

int main() {
    int n, m, a, b;
    scanf("%d %d", &n, &m);
    for (int i = 0; i<m; i++){
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
    }
    p[1] = 1;
    for (int i = 1; i<=n; i++){
        for (int j : adj[i]){
            p[j] += p[i]/adj[i].size();
        }
    }
    for (int i = 1; i<=n; i++){
        if (adj[i].size() == 0){
            printf("%.10lf\n", p[i]);
        }
    }
}