#include <bits/stdc++.h>

using namespace std;

int dp[1003][1003], A[1003], B[1003];
char S[1003], T[1003];

int main() {
    int N;
    scanf("%d", &N);
    scanf("%s", S);
    for (int i=0; i<N; i++){
        scanf("%d", &A[i]);
    }
    scanf("%s", T);
    for (int i = 0; i<N; i++){
        scanf("%d", &B[i]);
    }
    for (int i = 1; i<=N; i++){
        for (int j = 1; j<=N; j++){
            if (S[i-1]=='W' && T[j-1]=='L' && A[i-1] > B[j-1] || S[i-1]=='L' && T[j-1]=='W' && A[i-1] < B[j-1]){
                dp[i][j] = A[i-1] + B[j-1] + dp[i-1][j-1];
            }
            dp[i][j] = max(dp[i][j], dp[i-1][j]);
            dp[i][j] = max(dp[i][j], dp[i][j-1]);
        }
    }
    printf("%d", dp[N][N]);
    return 0;
}