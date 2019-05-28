#include <bits/stdc++.h>
using namespace std;

int a[200005];

int main() {
	int n;
    scanf("%d", &n);
    for (int i = 0; i<n; i++){
        scanf("%d", &a[i]);
    }
    sort(a, a+n);
    int p = 0;
    for (int i = 1; i<=n+1; i++){
        while (p < n && a[p]<i)
            p++;
        if (p == n){
            printf("%d", i-1);
            return 0;
        }
        p++;
    }
}