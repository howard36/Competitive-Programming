#include <bits/stdc++.h>
using namespace std;
#define ll long long

char a[100005], b[100005];

int main() {
    // freopen("data.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    scanf("%s", a);
    scanf("%s", b);
    ll zz = 0, zo = 0, oz = 0, oo = 0;
    for (int i = 0; i<n; i++){
        if (a[i] == '1'){
            if (b[i] == '1') oo++;
            else oz++;
        }
        else{
            if (b[i] == '1') zo++;
            else zz++;
        }
    }
    ll ans = zz*oz+zz*oo+oz*zo;
    printf("%lld\n", ans);
    // printf("%lld, %lld, %lld, %lld", zz, zo, oz, oo);
}