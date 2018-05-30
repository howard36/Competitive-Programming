#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll s[3003], c[3003], best[3003];

int main(){
    // freopen("data.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for (int i = 0; i<n; i++){
        scanf("%lld", &s[i]);
    }
    for (int i = 0; i<n; i++){
        scanf("%lld", &c[i]);
    }

    for (int i = 0; i<n; i++){
        best[i] += c[i];
        ll m = 1e15;
        for (int j = 0; j < i; j++){
            if (s[j] < s[i]){
                m = min(m, c[j]);
            }
        }
        best[i] += m;
        m = 1e15;
        for (int j = i+1; j < n; j++){
            if (s[j] > s[i]){
                m = min(m, c[j]);
            }
        }
        best[i] += m;
    }
    ll m = 1e15;
    for (int i = 0; i<n; i++){
        m = min(m, best[i]);
    }
    if (m == 1e15){
        printf("-1");
    }
    else
        printf("%lld", m);
}
