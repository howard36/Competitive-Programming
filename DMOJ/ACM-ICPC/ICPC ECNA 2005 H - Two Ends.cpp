#include <bits/stdc++.h>
using namespace std;

int dp[1003][1003];
int a[1003];

int main() {
    int n = 1, game = 1;
    while (true){
        scanf("%d", &n);
        if (n == 0)
            break;
        for (int i = 0; i<n; i++){
            scanf("%d", &a[i]);
        }
        for (int i = 0; i<=n; i++){
            dp[i][i] = 0;
            dp[i][i+1] = a[i];
        }
        for (int i = 2; i <= n; i++) {
            for (int l = 0; l <= n - i; l++){
                int left = a[l] - max(a[l+1], a[l+i-1]) + dp[(a[l+1] >= a[l+i-1] ? (l+2) : (l+1))][(a[l+1] >= a[l+i-1] ? (l+2) : (l+1)) + i-2];
                int right = a[l+i-1] - max(a[l], a[l+i-2]) + dp[(a[l] >= a[l+i-2] ? (l+1) : l)][(a[l] >= a[l+i-2] ? (l+1) : l) + i-2];
                dp[l][l+i] = max(left, right);
                // printf("dp[%d][%d] = %d, left = %d, right = %d\n", l, l+i, dp[l][l+i], left, right);
            }
        }
        printf("In game %d, the greedy strategy might lose by as many as %d points.\n", game, dp[0][n]);
        game++;
    }
}