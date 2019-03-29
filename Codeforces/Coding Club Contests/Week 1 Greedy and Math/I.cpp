#include <bits/stdc++.h>
using namespace std;
#define pi pair<int, int>

pi a[1003];

int main() {
    int s, n;
    scanf("%d %d", &s, &n);
    for (int i = 0; i<n; i++){
        scanf("%d %d", &a[i].first, &a[i].second);
    }
    sort(a, a+n);
    for (int i = 0; i<n; i++){
        if (s <= a[i].first){
            printf("NO");
            return 0;
        }
        s += a[i].second;
    }
    printf("YES");
}