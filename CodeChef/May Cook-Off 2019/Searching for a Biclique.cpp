#include <bits/stdc++.h>
using namespace std;

bitset<2000> adj[2000];

int main() {
    int n, m, k, a, b;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i<m; i++){
        scanf("%d %d", &a, &b);
        a--, b--;
        adj[a].set(b);
        adj[b].set(a);
    }
    for (int i = 0; i<n; i++){
        for (int j = 0; j<i; j++){
            if ((adj[i]&adj[j]).count() >= k){
                printf("YES");
                return 0;
            }
        }
    }
    printf("NO");
}