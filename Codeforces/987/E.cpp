#include <bits/stdc++.h>
#define ll long long

ll bit[1000006];
int n;

void update(int x, ll inc){
    for (; x<=n; x+=x&-x){
        bit[x] += inc;
    }
}

ll sum(int x){
    ll ans = 0;
    for (; x>0; x-=x&-x){
        ans += bit[x];
    }
    return ans;
}

int main(){
    scanf("%d", &n);
    ll inversions = 0;
    int a;
    for (int i = 0; i<n; i++){
        scanf("%d", &a);
        inversions += i-sum(a);
        update(a, 1);
    }
    if ((n+inversions)%2 == 0)
        printf("Petr");
    else
        printf("Um_nik");
}
