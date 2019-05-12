#include <bits/stdc++.h>

int main() {
    int a = 0, b = 0, c, n;
    scanf("%d", &n);
    while (n--){
        scanf("%d", &c);
        if (c == 1)
            a++;
        else
            b++;
    }
    if (b == 0){
        while (a--)
            printf("1 ");
    }
    else if (a == 0){
        while (b--)
            printf("2 ");
    }
    else{
        // a >= 1, b >= 1
        printf("2 1 ");
        b--; a--;
        while (b--)
            printf("2 ");
        while (a--)
            printf("1 ");
    }
}