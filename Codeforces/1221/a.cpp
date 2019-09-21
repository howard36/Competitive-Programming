#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int, int>

int a[102], b[102], f[20];

int main() {
	int n, q;
	scanf("%d", &q);
	while (q--) {
		scanf("%d", &n);
		for (int i = 0; i<12; i++)
			f[i] = 0;
		for (int i = 0; i<n; i++) {
			scanf("%d", &a[i]);
			b[i] = 0;
			while (a[i] > 1) {
				b[i]++;
				a[i] /= 2;
			}
			if (b[i] < 12)
				f[b[i]]++;
		}
		for (int i = 0; i<11; i++)
			f[i+1] += f[i]/2;
		if (f[11])
			printf("YES\n");
		else
			printf("NO\n");
	}
}
