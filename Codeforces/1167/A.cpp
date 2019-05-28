#include <bits/stdc++.h>

int main() {
    int t;
    scanf("%d", &t);
    while (t--){
        int n;
        scanf("%d", &n);
        char c;
        bool ans = false;
        for (int i = 0; i<n; i++){
            scanf(" %c", &c);
            if (c == '8' && n-i >= 11)
                ans = true;
        }
        if (ans){
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }
}