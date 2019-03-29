#include <bits/stdc++.h>
using namespace std;

double a[1003];

double med(int i, int j) {
	if ((j - i) % 2 == 1) {
		return a[i + (j - i) / 2];
	}
	else {
		return (a[i + (j - i) / 2] + a[i + (j - i) / 2 - 1]) / 2;
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lf", &a[i]);
	}
	sort(a, a + n);
	if (n == 1) {
		printf("%.lf %.2lf", a[0], a[0]);
	}
	else if (n == 2) {
		printf("%.2lf %.2lf", (a[0] + a[1]) / 2, (a[0] + a[1]) / 2);
	}
	else {
		double lo = min(min(a[1], (a[0] + med(1, n)) / 2), med(0, n));
		double hi = max(max(a[n - 2], (a[n - 1] + med(0, n - 1)) / 2), med(0, n));
		printf("%.2lf %.2lf", lo, hi);
	}
}