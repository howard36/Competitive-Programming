#include <bits/stdc++.h>

char a[2][102];
int count[102];

int main(){
    scanf("%s %s", a[0], a[1]);
    int n = strlen(a[0]);
    for (int i =0; i<n; i++){
        if (a[0][i] == '0')
            count[i]++;
        if (a[1][i] == '0')
            count[i]++;
    }
    int ans = 0;
    for (int i = 0; i<n; i++){
        if (count[i] == 2){
            if (i && count[i-1]){
                count[i]=0;
                ans++;
            }
            else if (i < n-1 && count[i+1]){
                count[i]=0;
                count[i+1]--;
                ans++;
            }
        }
    }
    printf("%d", ans);
}
