#include <bits/stdc++.h>

bool check(int x, int y){
    if (x > 2 && y > 2){
        return x < y;
    }
    else if (x == 1)
        return false;
    else if (y == 1)
        return true;
    else if (x == 2)
        return y != 3;
    else
        return x == 3;
}

int main() {
    int x, y;
    scanf("%d%d", &x, &y);
    if (x == y || x == 2 && y == 4 || x == 4 && y == 2){
        printf("=\n");
    }
    else if (check(x, y)){
        printf(">\n");
    }
    else
        printf("<\n");
}
