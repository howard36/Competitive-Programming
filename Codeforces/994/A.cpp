#include <bits/stdc++.h>


int in[10], s[10];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i<n; i++){
        scanf("%d", &s[i]);
    }
    for (int i = 0; i<m; i++){
        int x;
        scanf("%d", &x);
        in[x] = 1;
    }
    for (int i = 0; i<n; i++){
        if (in[s[i]]){
            printf("%d ", s[i]);
        }
    }
}
