#include <bits/stdc++.h>
using namespace std;

bool has[30];

int main() {
    // freopen("data.txt", "r", stdin);
    int n, k;
    scanf("%d%d", &n, &k);
    char c;
    for (int i = 0; i<n; i++){
        scanf(" %c", &c);
        has[c-'a'+1] = true;
        // printf("%c", c);
    }
    int num = 0, sum = 0;
    for (int i = 1; i<27; i++){
        if (has[i]){
            has[i+1] = false;
            sum += i;
            num++;
            // printf("Added %d\n", i);
        }
        if (num == k){
            printf("%d\n", sum);
            return 0;
        }
    }
    printf("-1");
}