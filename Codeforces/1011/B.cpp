#include <bits/stdc++.h>
using namespace std;

int cnt[102];

int main() {
    // freopen("data.txt", "r", stdin);
    int n, m, a;
    scanf("%d%d", &n, &m);
    for (int i = 0; i<m; i++){
        scanf("%d", &a);
        cnt[a]++;
    }
    for (int t = 100; t > 0; t--){
        int people = 0;
        for (int i = 1; i<101; i++){
            people += cnt[i]/t;
        }
        if (people >= n){
            printf("%d\n", t);
            return 0;
        }
    }
    printf("0");
}