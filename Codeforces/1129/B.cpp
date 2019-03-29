#include <bits/stdc++.h>
using namespace std;

int main() {
    int k;
    scanf("%d", &k);
    int n = 2000;
    int y = 1e6;
    for (; y; y--){
        if ((k+y)%n == 0)
            break;
    }
    int x = y - (k+y)/n;
    printf("%d\n", n);
    for (int i = 0; i<n-2; i++){
        printf("0 ");
    }
    printf("%d %d", -x, y);
}