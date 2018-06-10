#include <bits/stdc++.h>

int has[100005];

int main(){
    int n, k, r, x;
    scanf("%d%d%d", &n, &k, &r);
    int count = 0;
    for (int i = 0; i<k; i++){
        scanf("%d", &x);
        has[x] = 1;
        if (x < r)
            count++;
    }
    int ans = 0;
    for (int i = 0; i<=n-r; i++){
        if (count == 1){
            if (has[i+r-1] == 1)
                has[i+r-2] = 1;
            else
                has[i+r-1] = 1;
            ans++;
            count++;
        }
        if (count == 0){
            has[i+r-1] = 1;
            has[i+r-2] = 1;
            ans += 2;
            count += 2;
        }
        count += has[i+r] - has[i];
    }
    printf("%d\n", ans);
}
