#include <bits/stdc++.h>
using namespace std;

int a[20000], b[20000];

int main() {
	int n, odd = 0;
	scanf("%d", &n);
	for (int i = 0; i<n; i++) {
		scanf("%d", &a[i]);
		if (a[i] >= 0)
			b[i] = a[i]/2;
		else
			b[i] = (a[i]-1)/2;
		if ((a[i] + 100000) % 2 == 1) {
			b[i] += odd;
			odd = (odd+1)%2;
		}
		printf("%d\n", b[i]);
	}
}
