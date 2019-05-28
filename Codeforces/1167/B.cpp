#include <bits/stdc++.h>
using namespace std;

int ans[7], realans[7];

int query(int i, int j) {
	cout << "? " << i << ' ' << j << endl;
	int x;
	cin >> x;
	return x;
}

void test(int a, int b, int d, int v) {
	if (a % d == 0 && b % d == 0) {
		ans[2] = v;
	}
	if (a % d == 0 && b % d != 0) {
		ans[1] = v;
	}
	if (a % d != 0 && b % d == 0) {
		ans[3] = v;
	}
}

void solve(int t, int a) {
	if (ans[t])
		ans[t + 1] = a / ans[t];
	if (ans[t + 1])
		ans[t] = a / ans[t + 1];
}

int main() {
	for (int t = 0; t < 2; t++) {
		int a = query(1 + 3 * t, 2 + 3 * t);
		int b = query(2 + 3 * t, 3 + 3 * t);
		memset(ans, 0, sizeof ans);
		test(a, b, 5, 15);
		test(a, b, 7, 42);
		test(a, b, 23, 23);
		solve(1, a);
		solve(2, b);
		solve(1, a);
		if (!ans[1]) {
			ans[2] = a * b / (1 << 9);
			solve(1, a);
			solve(2, b);
		}
		for (int i = 1; i <= 3; i++) {
			realans[i + 3 * t] = ans[i];
		}
	}
    printf("! ");
    for (int i = 1; i<=6; i++){
        printf("%d ", realans[i]);
    }
}