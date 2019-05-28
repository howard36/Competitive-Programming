#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x, y, ans = 0;
    char c;
    scanf("%d %d %d", &n, &x, &y);
    for (int i = n-1; i>=0; i--){
        scanf(" %c", &c);
        if (i < x) {
            if (i == y)
                ans += (int)(c == '0');
            else
                ans += (int)(c == '1');            
        }
    }
    printf("%d", ans);
}