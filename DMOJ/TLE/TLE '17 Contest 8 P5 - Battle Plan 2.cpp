#include "bits/stdc++.h"

int a[200005], b[51], next[50][200005][18];
// If you deploy 2^k fighters of type i at position j, they destroy everything from j to next[i][j][k]-1, inclusive

int main(){
    // freopen("data.txt", "r", stdin);
    int N, K, Q;
    scanf("%d%d%d", &N, &K, &Q);
    for (int i = 0; i<N; i++){
        scanf("%d", &a[i]);
    }
    a[N] = 1e9+7;
    for (int i = 0; i<K; i++){
        scanf("%d", &b[i]);
    }
    for (int i = 0; i<K; i++){
        int l = 0, r = 0, sum = 0; // represents interval [l,r)
        while (l <= N){
            while (sum + a[r] <= b[i]){
                sum += a[r];
                r++;
            }
            next[i][l][0] = r;
            // printf("next[%d][%d][0] = %d\n", i, l, r);
            sum -= a[l];
            l++;
            if (l > r){
                sum += a[r];
                r++;
            }
        }
        for (int j = 1; j<18; j++){
            for (int k = 0; k <= N; k++){
                next[i][k][j] = next[i][next[i][k][j-1]][j-1];
                // printf("next[%d][%d][%d] = %d\n", i, k, j, next[i][k][j]);
            }
        }
    }
    int j, l, r;
    for (int i = 0; i<Q; i++){
        scanf("%d%d%d", &j, &l, &r);
        j--; l--; r--;
        int count = 0;
        for (int step = 17; step >= 0; step--){
            // printf("l = %d, step = %d, next[j][l][step] = %d\n", l, step, next[j][l][step]);
            if (next[j][l][step] <= r){
                l = next[j][l][step];
                count += (1 << step);
                // printf("stepping\n");
            }
        }
        if (next[j][l][0] > r){
            printf("%d\n", count+1);
        }
        else
            printf("-1\n");
    }
}