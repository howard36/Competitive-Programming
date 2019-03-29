#include <bits/stdc++.h>
using namespace std;

int L[20], R[20];
int dp[10][10][2][2][2];

int solve(int digit, int last, bool lowest, bool highest, bool zeros){
    int ans = 0;
    if (digit == 10) {
        return 1;
    }
    if (dp[digit][last][(int)lowest][(int)highest][(int)zeros] != -1)
        return dp[digit][last][(int)lowest][(int)highest][(int)zeros];
    if (lowest && highest && L[digit] == R[digit]){
        if (abs(L[digit]-last) < 2 && !zeros) return 0;
        else return solve(digit+1, L[digit], true, true, zeros && (L[digit]==0));
    }
    for (int i = 0; i<=9; i++){
        if (abs(i-last)<2 && !zeros) continue;
        if (lowest && i < L[digit]) continue;
        if (highest && i > R[digit]) continue;
        ans += solve(digit+1, i, (lowest && i == L[digit]), (highest && i == R[digit]), (zeros && i==0));
    }
    dp[digit][last][(int)lowest][(int)highest][(int)zeros] = ans;
    return ans;
}

int main() {
    int l, r;
    scanf("%d %d", &l, &r);
    for (int i = 9; i>=0; i--){
        L[i] = l%10;
        R[i] = r%10;
        l/=10;
        r/=10;
    }
    for (int i = 0; i<10; i++){
        for (int j = 0; j<10; j++){
            for (int k = 0; k<2; k++){
                for (int l = 0; l<2; l++){
                    for (int m = 0; m<2; m++){
                        dp[i][j][k][l][m] = -1;
                    }
                }
            }
        }
    }
    printf("%d", solve(0, 0, true, true, true));
}