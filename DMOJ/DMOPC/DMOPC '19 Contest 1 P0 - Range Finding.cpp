#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, a = 1e9, b=1, c;
	scanf("%d", &n);
	for (int i = 0; i<n; i++) {
		scanf("%d", &c);
		a = min(a, c);
		b = max(b, c);
	}
	printf("%d", b-a);
}
