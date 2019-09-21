#include <bits/stdc++.h>
using namespace std;
#define M 1000000007LL
#define ll long long

ll f[100][10004], p[10004];

int main() {
	f[0][0] = 2;
	p[0] = 1;
	for (int i = 1; i<10004; i++)
		p[i] = 2*p[i-1]%M;
	for (int i = 1; i<=12; i++) {
		for (int j = 0; j<=(1<<i); j++) {
			f[i][2*j] += f[i-1][j];
			f[i][2*j+1] += (f[i-1][j]*(f[i-1][j] - 1)/2)%M;
		}
		for (int j = 0; j<=(1<<i); j++) {
			for (int k = j+1; k<=(1<<i); k++) {
				f[i][j+k+1] += (f[i-1][j] * f[i-1][k])%M;
			}
		}
		for (int j = 0; j<=(1<<i); j++)
			f[i][j] %= M;
	}
	int n;
	scanf("%d", &n);
	while (n--) {
		int a, b = 0;
		scanf("%d", &a);
		while (a%2 == 0) {
			a /= 2;
			b++;
		}
		ll ans = 0;
		for (int j = 0; j<=(1<<b); j++) {
			ans = (ans + f[b][j] * p[2*j]) % M;
		}
		ans = (ans * p[a-1]) % M;
		printf("%lld\n", ans);
	}
}
