#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
// Problem I: Installing Apps
using namespace std;
int dp[502][502], store[502][502], pre[502][502], d[502], s[502], srt[502];
vector<int> apps;
bool cmp(int a, int b) {
    return (s[a] - d[a]) < (s[b] - d[b]);
}
int main() {
    int n, c; scanf("%d%d", &n, &c);
    for (int i = 1; i <= n; i++) scanf("%d%d", &d[i], &s[i]);
    for (int i = 1; i <= n; i++) srt[i] = i;
    sort(srt + 1, srt + n + 1, cmp);

    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0; store[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = 0; store[i][0] = 0; pre[i][0] = 0;
        for (int j = 1; j <= n; j++) {
            int temp = max(dp[i - 1][j - 1], store[i - 1][j - 1] + max(d[srt[i]], s[srt[i]]));
            if (temp < dp[i - 1][j]) {
                dp[i][j] = temp;
                store[i][j] = store[i - 1][j - 1] + s[srt[i]];
                pre[i][j] = j - 1;
            }
            else {
                dp[i][j] = dp[i - 1][j];
                store[i][j] = store[i - 1][j];
                pre[i][j] = j;
            }
        }
    }
    
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (dp[n][i] <= c)
            ans = i;
    }
    printf("%d\n", ans);
    for (int i = n; i > 0; i--) {
        if (pre[i][ans] < ans) apps.push_back(srt[i]);
        ans = pre[i][ans];
    }
    sort(apps.begin(), apps.end());
    for (int a : apps) printf("%d ", a);
    printf("\n");

    return 0;
}


