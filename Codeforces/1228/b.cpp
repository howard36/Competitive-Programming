#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll r[1003], c[1003], g[1003][1003];

int main() {
	ll w, h;
	scanf("%lld %lld", &h, &w);
	for (int i = 0; i<h; i++)
		scanf("%lld", &r[i]);
	for (int i = 0; i<w; i++)
		scanf("%lld", &c[i]);
	memset(g, -1, sizeof g);
	for (int i = 0; i<h; i++) {
		for (int j = 0; j<r[i]; j++) {
			g[i][j] = 0;
		}
		g[i][r[i]] = 1;
	}
	for (int j = 0; j<w; j++) {
		for (int i = 0; i<c[j]; i++) {
			if (g[i][j] == 1) {
				printf("0");
				return 0;
			}
			g[i][j] = 0;
		}
		if (g[c[j]][j] == 0) {
			printf("0");
			return 0;
		}
		g[c[j]][j] = 1;
	}
	ll ans = 1;
	for (int i = 0; i<h; i++) {
		for (int j = 0; j<w; j++) {
			if (g[i][j] == -1)
				ans = (ans*2)%1000000007;
		}
	}
	printf("%lld", ans);

}
