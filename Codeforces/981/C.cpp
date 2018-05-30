#include <bits/stdc++.h>
using namespace std;

int deg[100005];

int main() {
    // freopen("data.txt", "r", stdin);
    int N;
    scanf("%d", &N);
    int a, b;
    for (int i = 0; i<N-1; i++){
        scanf("%d%d", &a, &b);
        deg[a]++;
        deg[b]++;
    }
    int count = 0, count2 = 0;
    int center, minleaf = 1e6, maxleaf = 0;
    for (int i = 1; i<=N; i++){
        if (deg[i] > 2){
            count++;
            center = i;
        }
        if (deg[i] == 1){
            count2++;
            minleaf = min(minleaf, i);
            maxleaf = max(maxleaf, i);
        }
    }
    if (count > 1){
        printf("No\n");
    }
    else{
        printf("Yes\n");
        if (count == 1){
            printf("%d\n", count2);
            for (int i = 1; i<=N; i++){
                if (deg[i] == 1){
                    printf("%d %d\n", center, i);
                }
            }
        }
        else
            printf("1\n%d %d\n", minleaf, maxleaf);
    }
}
