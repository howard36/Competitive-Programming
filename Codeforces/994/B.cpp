#include <bits/stdc++.h>
#define pi pair<int,int>
#define ll long long
using namespace std;

pi knights[100005];
ll c[100005], ans[100005], cur[10], sum;

int main() {
    // freopen("data.txt", "r", stdin);
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i<n; i++){
        scanf("%d", &knights[i].first);
        knights[i].second = i;
    }
    sort(knights, knights+n);
    for (int i = 0; i<n; i++){
        scanf("%lld", &c[i]);
    }
    if (k == 0){
        for (int i = 0; i<n; i++){
            printf("%lld ", c[i]);
        }
        return 0;
    }
    for (int i = 0; i<n; i++){
        ans[knights[i].second] = sum + c[knights[i].second];
        if (c[knights[i].second] > cur[0]){
            sum += c[knights[i].second] - cur[0];
            cur[0] = c[knights[i].second];
        }
        sort(cur, cur+k);
    }
    for (int i = 0; i<n; i++){
        printf("%lld ", ans[i]);
    }
}
