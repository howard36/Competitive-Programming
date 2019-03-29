#include <bits/stdc++.h>
using namespace std;
#define pi pair<int, int>

int a[100005], x[400][300], G[400];
int b = 300;

int gcd(int x, int y) {
	if (y == 0)
		return x;
	return gcd(y, x % y);
}

void calculate(int i) {
	x[i][0] = a[i * b];
	G[i] = a[i * b];
	for (int j = 1; j < b; j++) {
		x[i][j] = x[i][j - 1] ^ a[i * b + j];
		G[i] = gcd(G[i], a[i * b + j]);
	}
	sort(x[i], x[i] + b);
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int b = 300, blocks = (n + b - 1) / b;
	for (int i = 0; i < blocks; i++) {
	}
	int q;
	scanf("%d", &q);
	while (q--) {
		int t;
		scanf("%d", &t);
		if (t == 1) {
			int idx, val;
			scanf("%d %d", &idx, &val);
			for (int i = 0; i < b; i++) {
			}
		}
		else {
		}
	}
}