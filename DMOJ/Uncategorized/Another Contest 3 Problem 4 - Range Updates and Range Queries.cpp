#include <bits/stdc++.h>
#define ll long long

ll bit[3][1000006];

void update(int t, int i, ll v){
    for (; i<1000006; i+=i&-i){
        bit[t][i]+=v;
    }
}

ll query(int t, int i){
    ll ans = 0;
    for (; i>0; i-=i&-i){
        ans += bit[t][i];
    }
}

ll updateAll(int l, int r, ll v){
    update(0, l, v);
    update(1, l, v*(-2*l+3));
    update(2, l, v*(l-1)*(l-2));
    update(0, r+1, -v);
    update(1, r+1, -v*(-2*l+3));
    update(2, r+1, -v*(l-1)*(l-2));
    update(0, r+1, v*(r-l+1)*(r-l+2));
}

ll queryAll(int i){
    return (query(2, i)*i*i + query(1, i)*i + query(0, i))/2;
}

int main() {
    freopen("data.txt", "r", stdin);
    int n, q, type, l, r, v;
    scanf("%d %d", &n, &q);
    while (q--){
        scanf("%d %d %d", &type, &l, &r);
        l++, r++;
        if (type == 1){
            scanf("%d", &v);
            updateAll(l, r, v);
        }
        else{
            printf("%lld\n", queryAll(r) - queryAll(l-1));
        }
    }
}