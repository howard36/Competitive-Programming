#include <bits/stdc++.h>
using namespace std;

int a[102];

int main() {
    int n, sum=0;
    scanf("%d", &n);
    for (int i = 0; i<n; i++){
        scanf("%d", &a[i]);
        sum+=a[i];
    }
    sort(a, a+n);
    int count = 0;
    while (2*sum < n*9){
        sum += 5-a[count];
        count++;
    }
    printf("%d", count);
}
