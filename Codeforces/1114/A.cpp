#include <bits/stdc++.h>

int main() {
    int x, y, z;
    int a, b, c;
    scanf("%d %d %d", &x, &y, &z);
    scanf("%d %d %d", &a, &b, &c);
    if (a >= x && a+b >= x+y && a+b+c >= x+y+z){
        printf("YES");
    }
    else {
        printf("NO");
    }
}