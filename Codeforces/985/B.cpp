#include <bits/stdc++.h>

int count[2003], arr[2003][2003];

int main(){
    int n, m;
    char c;
    scanf("%d%d", &n, &m);
    for (int i = 0; i<n; i++){
        for (int j = 0; j<m; j++){
            scanf(" %c", &c);
            if (c == '1'){
                arr[i][j] = 1;
                count[j]++;
            }
        }
    }
    bool ans = false;
    for (int i = 0; i<n; i++){
        bool good = true;
        for (int j = 0; j<m; j++){
            if (arr[i][j] && count[j]==1)
                good = false;
        }
        if (good){
            ans = true;
        }
    }
    if (ans)
        printf("YES");
    else
        printf("NO");
}
