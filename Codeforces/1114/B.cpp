#include <bits/stdc++.h>
using namespace std;

int a[200005], b[200005];

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i<n; i++){
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    sort(b, b+n);
    int cutoff = b[n - m*k];
    int cutoffFreq = 0;
    long long sum = 0;
    for (int i = n-m*k; i < n; i++){
        sum += b[i];
        if (b[i] == cutoff)
            cutoffFreq++;
    }
    printf("%lld\n", sum);
    // printf("%d %d\n", cutoff, cutoffFreq);
    int cnt = 0;
    int groups = 0;
    for (int i = 0; i<n; i++){
        if (a[i] > cutoff)
            cnt++;
        else if (a[i] == cutoff && cutoffFreq > 0){
            cnt++;
            cutoffFreq--;
        }
        if (cnt == m && groups < k-1){
            printf("%d ", i+1);
            cnt = 0;
            groups++;
        }
    }
    printf("\n");
}