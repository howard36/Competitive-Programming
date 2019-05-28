#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	int q;
    scanf("%d", &q);
	while (q--) {
		ll a, b, m;
		scanf("%lld %lld %lld", &a, &b, &m);
        if (a == b) {
            printf("1 %lld\n", a);
            continue;
        }
        // printf("a = %lld ", a);
		int k = 1;
		while (b > (1LL << (k - 2)) * (a + m))
			k++;
		if (b < (1LL << (k - 2)) * (a + 1)) {
			printf("-1\n");
			continue;
		}
		vector<ll> r;
		ll get = b - (1LL << (k - 2)) * (a + 1);
		for (int i = k - 3; i >= 0; i--) {
			r.push_back(min((get >> i) + 1, m));
			get -= (r[r.size() - 1]-1) << i;
		}
        r.push_back(get + 1);
        r.push_back(0);
        // for (int i = 0; i<k-1; i++) {
        //     printf("r[%d] = %lld\n", i, r[i]);
        // }
        ll psa = 0;
        printf("%d ", k);
        for (int i = 0; i<k; i++){
            printf("%lld ", a);
            psa += a;
            a = psa + r[i];
        }
        printf("\n");
	}
}