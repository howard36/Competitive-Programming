#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	if (a == 1 && b == 1)
		printf("0");
	else {
		if (abs(a - b) % 3 == 0)
			printf("%d", a + b - 3);
		else
			printf("%d", a + b - 2);
	}
}