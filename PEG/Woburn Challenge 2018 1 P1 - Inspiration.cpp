#include <bits/stdc++.h>

int a[50004][11];

int main() {
    int R, C, k;
    scanf("%d %d %d", &R, &C, &k);
    for (int i = 0; i<R; i++){
        for (int j = 0; j<C; j++){
            scanf("%d", &a[i][j]);
        }
    }
    int ans = 0;
    for (int c = 0; c<C; c++){
        int cnt = 0;
        for (int r = 0; r < R; r++){
            if (a[r][c] == 2 && cnt)
                ans++;
            if (a[r][c] == 1)
                cnt++;
            if (r >= k && a[r-k][c]==1)
                cnt--;
        }
    }
    printf("%d", ans);
}