#include <bits/stdc++.h>
using namespace std;

int D[31][31], convert[3][31];

int main() {
    int N, C;
    scanf("%d%d", &N, &C);
    for (int i = 1; i<=C; i++){
        for (int j = 1; j<=C; j++){
            scanf("%d", &D[i][j]);
        }
    }
    for (int i = 1; i<=N; i++){
        for (int j = 1; j<=N; j++){
            int x;
            scanf("%d", &x);
            for (int k = 1; k<=C; k++){
                convert[(i+j)%3][k] += D[x][k];
            }
        }
    }
    int best = 1e9;
    for (int i = 1; i<=C; i++){
        for (int j = 1; j<=C; j++){
            for (int k = 1; k<=C; k++){
                if (i==j || j==k || k==i)
                    continue;
                best = min(best, convert[0][i] + convert[1][j] + convert[2][k]);
            }
        }
    }
    printf("%d", best);
}
