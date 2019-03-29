#include <bits/stdc++.h>
using namespace std;

int a[100005];

int main() {
    freopen("data2.txt", "r", stdin);
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i<n; i++){
        scanf("%d", &a[i]);
    }
    for (int i = 0; i<m; i++){
        int t, l, r;
        scanf("%d %d %d", &t, &l, &r);
        if (t == 0){
            sort(a+l-1, a+r);
        }
        else{
            sort(a+l-1, a+r, greater<int>());
        }
    }
    int q;
    scanf("%d", &q);
    printf("%d\n", a[q-1]);
}