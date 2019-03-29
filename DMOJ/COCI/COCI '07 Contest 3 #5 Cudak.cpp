#include <bits/stdc++.h>
#define ll long long

int a[20], b[20];

ll dp[15][10][10][136];

ll solve(int pos, int lo, int hi, int sum, bool lowest, bool highest) {
    if (dp[pos][lo][hi][sum] != -1) {
        return dp[pos][lo][hi][sum];
    }
	if (pos == 14) {
		return (lo <= sum && sum <= hi) ? 1 : 0;
	}
	ll ans = 0;
	for (int i = lo; i <= hi; i++) {
		ans += solve(pos + 1, (i == lo && lowest) ? a[pos + 1] : 0, (i == hi && highest) ? b[pos + 1] : 9, sum - i, i == lo && lowest, i == hi && highest);
	}
    dp[pos][lo][hi][sum] = ans;
	return ans;
}

int main() {
    for (int i = 0; i<15; i++){
        for (int j = 0; j<10; j++){
            for (int k = 0; k<10; k++){
                for (int l = 0; l<136; l++){
                    dp[i][j][k][l] = -1;
                }
            }
        }
    }
	ll A, B;
    int S;
	scanf("%lld %lld %d", &A, &B, &S);
	for (int i = 14; i >= 0; i--) {
		a[i] = A % 10;
		b[i] = B % 10;
		A /= 10;
		B /= 10;
	}
    printf("%lld\n", solve(0, a[0], b[0], S, true, true));
    int sum = 0;
    for (int i = 0; i<15; i++){
        sum += a[i];
    }
    int digit = 14;
    while (sum < S){
        if (a[digit] == 9)
            digit--;
        else {
            a[digit]++;
            sum++;
        }
    }
    digit = 0;
    while (a[digit] == 0)
        digit++;
    for (; digit < 15; digit++){
        printf("%d", a[digit]);
    }
}