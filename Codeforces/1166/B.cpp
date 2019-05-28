#include <bits/stdc++.h>

char v[5] = {'a', 'e', 'i', 'o', 'u'};

int main() {
    int k;
    scanf("%d", &k);
    for (int d = 5; d<=k; d++){
        if (k%d == 0 && k/d >= 5){
            int d2 = k/2;
            for (int i = 0; i<k; i++){
                int a = i%d, b = i/d;
                printf("%c", v[(a+b)%5]);
            }
            return 0;
        }
    }
    printf("-1");
}