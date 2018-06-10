#include <bits/stdc++.h>
using namespace std;

int a[200005];

int main() {
    // freopen("data.txt", "r", stdin);
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    sort(a, a+n);
    int count = 0;
    int equal = 0;
    for (int i = 0; i<n-1; i++){
        if (a[i+1]-a[i] > k)
            count += equal + 1;
        if (a[i] == a[i+1])
            equal++;
        else
            equal = 0;
    }
    count += equal+1;
    printf("%d", count);
}
