#include <bits/stdc++.h>
using namespace std;

int dp[1000006];

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++){
        dp[i] = dp[i-1]+1;
        int coin = 6;
        while (i - coin >= 0){
            dp[i] = min(dp[i], dp[i-coin]+1);
            coin *= 6;
        }
        coin = 9;
        while (i - coin >= 0){
            dp[i] = min(dp[i], dp[i-coin]+1);
            coin *= 9;
        }
    }
    printf("%d", dp[N]);
}
