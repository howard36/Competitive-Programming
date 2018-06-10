#include <bits/stdc++.h>
using namespace std;

int m[1003][1003];

int main() {
    // freopen("data.txt", "r", stdin);
    int n, a, b;
    bool swapped = false;
    scanf("%d%d%d", &n, &a, &b);
    if (a<b) {
        swap(a, b);
        swapped = true;
    }
    if (b != 1 || a > n) {
        printf("NO\n");
        return 0;
    }
    if (a == 1){
        if (n == 2 || n == 3){
            printf("NO\n");
            return 0;
        }
        printf("YES\n");
        for (int i = 0; i < n-1; i++){
            m[i][i+1] = 1;
            m[i+1][i] = 1;
        }
        for (int i = 0; i<n; i++){
            for (int j = 0; j<n; j++){
                printf("%d", m[i][j]);
            }
            printf("\n");
        }
        return 0;
    }
    printf("YES\n");
    for (int i = 0; i<a-1; i++){
        for (int j = 0; j<n; j++){
            m[i][j] = 1;
            m[j][i] = 1;
        }
    }
    for (int i = 0; i<n; i++)
        m[i][i] = swapped ? 0 : 1;
    for (int i = 0; i<n; i++){
        for (int j = 0; j<n; j++){
            if (swapped)
                printf("%d", m[i][j]);
            else
                printf("%d", 1-m[i][j]);
        }
        printf("\n");
    }
}
