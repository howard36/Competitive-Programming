#include <bits/stdc++.h>

using namespace std;

int main() {
    int p, x, y, t = -1e9, b = 1e9, l = 1e9, r = -1e9;
    scanf("%d", &p);
    while (p--){
        scanf("%d %d", &x, &y);
        t = max(t, y);
        b = min(b, y);
        l = min(l, x);
        r = max(r, x);
    }
    printf("%d", 2*(r-l+t-b));
    return 0;
}