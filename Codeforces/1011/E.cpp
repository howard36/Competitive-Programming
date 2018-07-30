#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    while (b){
        int t = b;
        b = a%b;
        a = t;
    }
    return a;
}

int main() {
    int n, k, a, orig;
    scanf("%d%d", &n, &k);
    orig = k;
    for (int i = 0; i<n; i++){
        scanf("%d", &a);
        k = gcd(k, a);
    }
    printf("%d\n", orig/k);
    for (int i = 0; i<orig/k; i++){
        printf("%d ", k*i);
    }
}