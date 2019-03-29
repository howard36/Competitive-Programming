#include <bits/stdc++.h>
using namespace std;

int a[5];

int main() {
	int n;
	scanf("%d", &n);
	int s;
	for (int i = 0; i < n; i++) {
		scanf("%d", &s);
		a[s]++;
	}
	int ans = 0;
	ans += a[4];
	ans += a[3];
	a[1] = max(0, a[1] - a[3]);
	ans += (a[1] + 2 * a[2] + 3) / 4;
    printf("%d", ans);
}