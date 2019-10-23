#include <bits/stdc++.h>
using namespace std;

int a[1000006], b[1<<20], c[1<<20];

int main() {
	string s;
	cin >> s;
	int n = s.length();
	for (int i = 0; i<n; i++)
		a[i] = s[i]-'a';
	int mask = 0, j = 0;
	for (int i = 0; i<n; i++) {
		while (j < n && (mask>>a[j])%2 == 0) {
			mask |= 1<<a[j];
			j++;
		}
		b[mask] = 1;
		mask -= (1<<i);
	}
	for (int i = 0; i<20; i++) {
		for (int j = 0; j < (1<<20); j++) {
			if ((j>>i)&1) {
				b[j-(1<<i)] |= b[j];
				c[j]++;
			}
		}
	}
	for (int i = 0; i<(1<<20); i++) {
		c[i] *= b[i];
	}
	for (int i = 0; i<20; i++) {
		for (int j = 0; j<(1<<20); j++) {
			if ((j>>i)&1)
				c[j] = max(c[j], c[j-(1<<i)]);
		}
	}
	int ans = 0;
	for (int i = 0; i<(1<<20); i++) {
		if (b[i])
			ans = max(ans, c[i] + c[i^((1<<20)-1)]);
	}
	printf("%d", ans);
}
