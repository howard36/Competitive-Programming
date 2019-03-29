#include <bits/stdc++.h>

int a[4];

int main() {
    for (int i = 1; i<=3; i++){
        scanf("%d", &a[i]);
    }
    for (int i = 1; i<=3; i++){
        if (a[a[a[a[i]]]] != 0){
            printf("NO");
            return 0;
        }
    }
    printf("YES");
}