#include <bits/stdc++.h>
using namespace std;

int a[1000006], b[1000006];

int main() {
	string s;
	cin >> s;
	int n = s.length();
	for (int i = 1; i <= n; i++) {
		char c = s[i - 1];
		if (c == '?') {
			a[i] = -1;
			b[i] = -1;
		}
		else if (c == '*') {
			a[i] = -1;
			b[i] = 1;
		}
		else {
			a[i] = c - '0';
			b[i] = 0;
		}
	}
	a[0] = a[n + 1] = -1;
	b[0] = b[n + 1] = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] == 0) {
			if (b[i - 1] == 1) {
				printf("0");
				return 0;
			}
			else {
				b[i - 1] = 0;
			}
			if (b[i + 1] == 1) {
				printf("0");
				return 0;
			}
			else {
				b[i + 1] = 0;
			}
		}
		else if (a[i] == 2) {
			if (b[i - 1] == 0) {
				printf("0");
				return 0;
			}
			else {
				b[i - 1] = 1;
			}
			if (b[i + 1] == 0) {
				printf("0");
				return 0;
			}
			else {
				b[i + 1] = 1;
			}
		}
		else if (a[i] == 1) {
			if (b[i - 1] != -1 && b[i + 1] != -1 && b[i - 1] + b[i + 1] != 1) {
				printf("0");
				return 0;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] == 1) {
			if (b[i - 1] != -1) {
				b[i + 1] = 1 - b[i - 1];
			}
		}
	}
	for (int i = n; i >= 1; i--) {
		if (a[i] == 1) {
			if (b[i + 1] != -1) {
				b[i - 1] = 1 - b[i + 1];
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (b[i] == -1)
			ans++;
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] == 1) {
			if (b[i - 1] == -1 && b[i + 1] == -1) {
				ans--;
			}
		}
	}
	long long p = 1;
	for (int i = 0; i < ans; i++) {
		p = (2 * p) % 1000000007LL;
	}
	printf("%lld", p);
}