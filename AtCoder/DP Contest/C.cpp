#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	int a, b, c, A = 0, B = 0, C = 0;
	while (n--) {
		scanf("%d %d %d", &a, &b, &c);
		int AA = max(B, C) + a;
		int BB = max(A, C) + b;
		int CC = max(A, B) + c;
		A = AA, B = BB, C = CC;
	}
	printf("%d", max(max(A, B), C));
}