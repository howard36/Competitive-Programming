#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int x = min(a, min(c, d));
    int y = min(a - x, b);
    printf("%d", 256*x + 32*y);
}