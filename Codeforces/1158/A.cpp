#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll b[100005], g[100005];

int main() {
    int n, m;
    ll B = 0, G = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i<n; i++){
        scanf("%lld", &b[i]);
        B += b[i];
    }
    for (int i = 0; i<m; i++){
        scanf("%lld", &g[i]);
        G += g[i];
    }
    sort(b, b+n, greater<ll>());
    sort(g, g+m);
    if (b[0] > g[0]) {
        printf("-1");
    }
    else if (b[0] == g[0]){
        printf("%lld", G+m*(B-b[0]));
    }
    else {
		printf("%lld", (G-g[0]+b[0]) + (g[0]+(m-1)*b[1]) + m*(B-b[0]-b[1]) );
    }
}