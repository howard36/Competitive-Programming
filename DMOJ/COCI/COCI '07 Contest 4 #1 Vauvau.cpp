#include <bits/stdc++.h>

int main() {
    int a, b, c, d;
    int x;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    for (int i = 0; i<3; i++){
        scanf("%d", &x);
        int X = x;
        x %= (a+b);
        int count = 0;
        if (x <= a)
            count++;
        X %= (c+d);
        if (X <= c)
            count++;
        if (count == 2){
            printf("both\n");
        }
        else if (count == 1){
            printf("one\n");
        }
        else{
            printf("none\n");
        }
    }
}
