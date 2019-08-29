#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int c = 1; c <= t; c++) {
		string s;
		cin >> s;
		int n = s.length();
		int m = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == 'B')
				m++;
		}
		printf("Case #%d: ", c);
		if (m == 0 && n == 1) {
			printf("Y\n");
		}
		else if (m == 1 && n == 3) {
			printf("Y\n");
		}
		else if (m >= 2 && m < n - 1) {
			printf("Y\n");
		}
		else {
			printf("N\n");
		}
	}
}