#include <bits/stdc++.h>
using namespace std;

int prime[4000006];

int main() {
    for (int i = 2; i<4000006; i++){
        prime[i] = 1;
    }
    for (int i = 2; i<2001; i++){
        if (prime[i]){
            for (int j = i*i; j<4000006; j+=i){
                prime[j] = 0;
            }
        }
    }
    int t;
    scanf("%d", &t);
    while (t--){
        int n;
        scanf("%d", &n);
        for (int i = 2; i<2*n; i++){
            if (prime[i] && prime[2*n-i]){
                printf("%d %d\n", i, 2*n-i);
                break;
            }
        }
    }
}