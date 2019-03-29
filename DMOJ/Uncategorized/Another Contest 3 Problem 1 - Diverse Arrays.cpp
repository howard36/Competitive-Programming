#include <bits/stdc++.h>
#define ll long long

int dp[1000006], freq[1000006], a[1000006];

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i<n; i++){
        scanf("%d", &a[i]);
    }
    int r = 1, cnt = 1;
    ll ans = 0;
    freq[a[0]] = 1;
    for (int l = 0; l<n; l++){
        while (cnt < k && r < n) {
            if (freq[a[r]] == 0)
                cnt++;
            freq[a[r]]++;
            r++;
        }
        if (cnt == k)
            ans += n+1-r;
        else
            break;
        freq[a[l]]--;
        if (freq[a[l]] == 0)
            cnt--;
    }
    printf("%lld\n", ans);
}