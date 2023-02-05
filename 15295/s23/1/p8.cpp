#include <bits/stdc++.h>
using namespace std;

int a[1003], c[1003][3], dp[1003][3];

int range(int t, int l, int r) {
    return c[r][t] - c[l][t];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }

    while (n > 0 && a[n-1] == 0) n--;

    int s = 0;
    while (s < n && a[s] != 0) s++;

    n -= s;
    for (int i = 0; i < n; i++)
        a[i] = a[i+s];
    reverse(a, a+n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            c[i+1][j] = c[i][j];
        }
        c[i+1][a[i]]++;
    }

    dp[0][1] = dp[0][2] = c[n][0];
    for (int i = 1; i <= n; i++) {
        for (int t1 = 1; t1 <= 2; t1++) {
            int t2 = 3-t1;
            dp[i][t1] = 1e9;
            for (int j = 0; j < i; j++) {
                dp[i][t1] = min(dp[i][t1], i-j+range(0,j,n)+2*range(t2,j,i)+dp[j][t2]);
            }
            for (int j = 0; j <= i; j++) {
                dp[i][t1] = min(dp[i][t1], i+range(0,0,n)+range(t2,j,i)+range(t2,0,i)+2*range(t1,0,j));
            }
        }
        dp[i][1] = min(dp[i][1], range(0,i,n)+dp[i][2]);
        dp[i][2] = min(dp[i][2], range(0,i,n)+dp[i][1]);
    }

    int ans = s + min(dp[n][1], dp[n][2]);
    cout << ans << endl;
}
