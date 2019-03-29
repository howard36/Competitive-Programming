#include <bits/stdc++.h>
using namespace std;
#define pi pair<int, int>
#define ll long long

pi a[1003];

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i<n; i++){
        scanf("%d %d", &a[i].first, &a[i].second);
    }
    ll ans = 0;
    sort(a, a+n);
    for (int i = 0; i<n; i++){
        if (a[i].first >= 0)
            break;
        ans += -2LL*a[i].first*((a[i].second+k-1)/k);
        // printf("finished i = %d, ans = %lld\n", i, ans);
        for (int rem = (k - a[i].second%k) % k; a[i+1].first < 0; i++) {
            // printf("i = %d, rem = %d\n", i, rem);
            if (rem < a[i+1].second){
                a[i+1].second -= rem;
                break;
            }
            else {
                rem -= a[i+1].second;
                a[i+1].second = 0;
                // printf("finished i + 1 = %d on the way back\n", i + 1, ans);
            }
        }
        a[i].second = 0;
    }
    // printf("%lld\n", ans);
    sort(a, a+n, greater<pi>());
    for (int i = 0; i<n; i++){
        if (a[i].first <= 0)
            break;
        ans += 2LL*a[i].first*((a[i].second+k-1)/k);
        for (int rem = (k - a[i].second%k) % k; a[i+1].first > 0; i++) {
            if (rem < a[i+1].second){
                a[i+1].second -= rem;
                break;
            }
            else {
                rem -= a[i+1].second;
                a[i+1].second = 0;
            }
        }
        a[i].second = 0;
    }
    printf("%lld\n", ans);
}