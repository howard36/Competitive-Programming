#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007LL

ll a[3];

ll ch[3][200005], psa[3][200005];


inline ll mult(ll x, ll y) { return (x * y) % mod; }
inline ll add(ll x, ll y) { return (x + y) % mod; }

ll inv(ll x) {
	ll e = mod - 2;
	ll p = x;
	ll ans = 1;
	while (e > 0) {
		if (e % 2 == 1)
            ans = mult(ans, p);
		p = mult(p, p);
        e /= 2;
	}
	return ans;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		a[5 - x - y]++;
	}
	int A = a[0], B = a[1], C = a[2];
	for (int i = 0; i < 3; i++) {
		int N = a[i];
		ch[i][0] = 1;
        psa[i][0] = 1;
		for (int k = 1; k <= N; k++) {
			ch[i][k] = mult(mult(ch[i][k - 1], N - k + 1), inv(k));
            psa[i][k] = add(psa[i][k-1], ch[i][k]);
		}
	}
    ll ans = 0;
    for (int a = 0; a<=A; a++){
        if (a < B && a < C)
            ans = add(ans, mult(ch[0][a], mult(psa[1][B-a-1], psa[2][C-a-1])));
    }
    printf("%lld", ans);
}