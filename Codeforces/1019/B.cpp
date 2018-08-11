#include <bits/stdc++.h>
using namespace std;

int n;

int query(int i) {
    int a, b;
    printf("? %d\n", i);
    fflush(stdout);
    scanf("%d", &a);
    printf("? %d\n", i + n / 2);
    fflush(stdout);
    scanf("%d", &b);
    return a - b;
}

int main() {
    scanf("%d", &n);
    int q1 = query(1);
    if (q1 % 2 == 1 || q1 % 2 == -1) {
        printf("! -1\n");
        fflush(stdout);
        return 0;
    }
    if (q1 == 0) {
        printf("! 1\n");
        fflush(stdout);
        return 0;
    }
    int lo = 1, hi = n / 2;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        int q = query(mid);
        if (q == 0) {
            printf("! %d\n", mid);
            fflush(stdout);
            return 0;
        }
        if (q * q1 > 0) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    printf("! %d\n", lo);
    fflush(stdout);
    return 0;
}