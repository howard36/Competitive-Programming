#include <bits/stdc++.h>
using namespace std;

int x[100005];

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int k, n;
		scanf("%d %d", &k, &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &x[i]);
		}
		int dim = 0;
		for (int i = 0; i < k; i++) {
			int found = -1;
			for (int j = dim; j < n; j++) {
				if ((x[j] >> i) & 1) {
					found = j;
					break;
				}
			}
			if (found != -1) {
				swap(x[dim], x[found]);
				for (int j = dim + 1; j < n; j++) {
					if ((x[j] >> i) & 1) {
						x[j] ^= x[dim];
					}
				}
				dim++;
			}
		}
		printf("%d\n", 1 << (k - dim));
	}
}