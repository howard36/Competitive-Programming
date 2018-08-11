#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
    int n;
    scanf("%d", &n);
    int s = 0;
    while (s*(s-1)<=n) s++;
    s--;
    for (int i = s*(n/s)+1; i<=n; i++) {
        printf("%d ", i);
    }
    for (int i = n/s-1; i>=0; i--){
        for (int j = 1; j<=s; j++){
            printf("%d ", s*i+j);
        }
    }
}