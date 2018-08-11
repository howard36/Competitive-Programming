#include <bits/stdc++.h>
using namespace std;
#define ll long long

int sum[1003];

int main() {
    int n, a, b, c, d;
    scanf("%d", &n);
    for (int i = 0; i<n; i++){
        scanf("%d %d %d %d", &a, &b, &c, &d);
        sum[i] = a+b+c+d;
    }
    int rank = 1;
    for (int i = 0; i<n; i++){
        if (sum[i] > sum[0])
            rank++;
    }
    printf("%d", rank);
}