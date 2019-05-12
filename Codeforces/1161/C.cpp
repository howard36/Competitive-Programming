#include <bits/stdc++.h>
using namespace std;

int a[100];

int main() {
	int n;
	scanf("%d", &n);
	int m = 1e9;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		m = min(m, a[i]);
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == m)
			cnt++;
	}
	if (cnt > n / 2) {
		printf("Bob");
	}
	else {
		printf("Alice");
	}
}