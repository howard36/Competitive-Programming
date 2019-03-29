#include <bits/stdc++.h>
using namespace std;
#define pi pair<int, int>

set<pi> S[4];
int p[200005], a[200005], b[200005];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i<n; i++){
        scanf("%d", &p[i]);
    }
    for (int i = 0; i<n; i++){
        scanf("%d", &a[i]);
    }
    for (int i = 0; i<n; i++){
        scanf("%d", &b[i]);
    }
    for (int i = 0; i < n; i++){
        S[a[i]].insert(pi(p[i], i));
        S[b[i]].insert(pi(p[i], i));
    }
    int m;
    scanf("%d", &m);
    for (int i = 0; i<m; i++){
        int c;
        scanf("%d", &c);
        if (S[c].size() == 0){
            printf("-1 ");
            continue;
        }
        pi P = *S[c].begin();
        printf("%d ", P.first);
        int idx = P.second;
        S[a[idx]].erase(pi(p[idx], idx));
        S[b[idx]].erase(pi(p[idx], idx));
    }
}