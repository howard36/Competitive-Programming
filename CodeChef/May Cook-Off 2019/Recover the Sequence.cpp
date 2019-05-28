#include <bits/stdc++.h>
#define ll long long

ll a[100005];

bool check(ll i, ll j, ll k){
    return (a[i]-a[j])*(j-k) == (a[j]-a[k])*(i-j);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--){
        int n;
        scanf("%d", &n);
        for (int i = 0; i<n; i++){
            scanf("%lld", &a[i]);
        }
        ll d, idx;
        if (check(0, 1, 2)){
            d = a[1]-a[0];
            idx = 0;
        }
		else if (check(0, 1, 3)) {
			d = a[1] - a[0];
			idx = 0;
		}
        else if (check(0, 2, 3)){
			d = a[3] - a[2];
			idx = 0;
		}
		else {
			d = a[3] - a[2];
            idx = 1;
		}
        for (int i = 0; i<n; i++){
            printf("%lld ", a[idx] + d*(i-idx));
        }
        printf("\n");
    }
}