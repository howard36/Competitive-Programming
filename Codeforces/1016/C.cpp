#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll m[300003][2], U[300005][2], dp[300005][2], post[300005];

int main() {
    ll N;
    scanf("%lld", &N);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &m[i][0]);
    }
    for (int i = 0; i < N; i++) {
        scanf("%lld", &m[i][1]);
    }
    for (int i = N - 1; i >= 0; i--) {
        post[i] = post[i + 1] + m[i][0] + m[i][1];
    }
    dp[N - 1][0] = U[N - 1][0] = m[N - 1][1];
    dp[N - 1][1] = U[N - 1][1] = m[N - 1][0];
    for (ll i = N - 2; i >= 0; i--) {
        U[i][0] = U[i + 1][0] + post[i + 1] + (2 * (N - i) - 1) * m[i][1];
        U[i][1] = U[i + 1][1] + post[i + 1] + (2 * (N - i) - 1) * m[i][0];
    }
    for (ll i = N - 2; i >= 0; i--) {
        dp[i][0] = max(U[i][0], m[i][1] + dp[i + 1][1] + 2 * post[i + 1]);
        dp[i][1] = max(U[i][1], m[i][0] + dp[i + 1][0] + 2 * post[i + 1]);
    }
    printf("%lld\n", dp[0][0]);
}