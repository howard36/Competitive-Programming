#include <bits/stdc++.h>
using namespace std;

int mult[40];

int main() {
    int n, m, res;
    scanf("%d%d", &m, &n);
    for (int i = 0; i<n; i++){
        printf("1\n");
        fflush(stdout);
        scanf("%d", &res);
        if (res == 0){
            exit(0);
        }
        mult[i] = res;
    }
    int q = 0, lo = 1, hi = m;
    while (lo < hi){
        int mid = (lo+hi)/2;
        printf("%d\n", mid);
        fflush(stdout);
        scanf("%d", &res);
        if (res == 0){
            exit(0);
        }
        res *= mult[q%n];
        q++;
        if (res == 1){
            lo = mid+1;
        }
        else{
            hi = mid-1;
        }
    }
    printf("%d\n", lo);
    fflush(stdout);
    scanf("%d", &res);
    if (res == 0){
        exit(0);
    }
}