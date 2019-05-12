#include <bits/stdc++.h>
#define ll long long
#define P 1000000007LL
#define Q 998244353LL
using namespace std;

ll powp[100005], powq[100005], h[100005], z[100005];
int n, m;

void add(int i, int d) {
	h[i] += Q * powp[d] + powq[d];
}

void calcZ() {
	int r = 0, ridx = 0;
	for (int l = 1; l < n; l++) {
        if (z[l-ridx] < r-l)
            z[l] = z[l-ridx];
        else {
			while (r < n - 1 && h[r + 1] == h[r + 1 - l])
				r++;
			z[l] = r - l + 1;
		}
		if (z[l] + l > r) {
			r = z[l] + l;
			ridx = l;
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	powp[0] = powq[0] = 1;
	for (int i = 1; i < n; i++) {
		powp[i] = 2 * powp[i - 1] % P;
		powq[i] = 2 * powq[i - 1] % Q;
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		a--;
		b--;
		add(a, (b - a + n) % n);
		add(b, (a - b + n) % n);
	}
	// for (int i = 0; i < n; i++) {
	// 	printf("h[%d] = %lld\n", i, h[i]);
	// }
	calcZ();
	// for (int i = 0; i < n; i++) {
	// 	printf("z[%d] = %lld\n", i, z[i]);
	// }
	for (int i = n - 1; i > 0; i--) {
		if (z[i] == n - i && n % i == 0) {
			printf("Yes\n");
			// printf("%d\n", i);
			return 0;
		}
	}
	printf("No\n");
}