#include <bits/stdc++.h>

int m[100005], M[100005], has[100005];

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i<k; i++){
        int a;
        scanf("%d", &a);
        a--;
        if (has[a] == 0)
            m[a] = i;
        has[a] = 1;
        M[a] = i;
    }
    int ans = 0;
    for (int i = 0; i<n; i++){
        ans += 1-has[i];
    }
    for (int i = 0; i<n-1; i++){
        ans += 2;
        if (has[i] && has[i+1]){
            if (m[i] < M[i+1])
                ans--;
            if (M[i] > m[i+1])
                ans--;
        }      
    }
    printf("%d", ans);
}
