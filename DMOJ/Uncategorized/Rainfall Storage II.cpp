#include <bits/stdc++.h>
using namespace std;

int a[1000006], l[1000006], r[1000006];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i<=n; i++){
        scanf("%d", &a[i]);
    }
    // printf("Hi");
    for (int i = 1; i<=n; i++){
        l[i] = max(l[i-1], a[i]);
    }
    // printf("Hi");
    for (int i = n; i>0; i--){
        r[i] = max(r[i+1], a[i]);
    }
    // printf("Hi");
    long long ans = 0;
    for (int i = 1; i<=n; i++){
        ans += min(l[i], r[i]) - a[i];
    }
    printf("%lld", ans);
}