#include <bits/stdc++.h>
using namespace std;

int m[100005], needed[100005];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &m[i]);
	}
	for (int i = n - 1; i >= 0; i--) {
		needed[i] = max(m[i], needed[i + 1] - 1);
	}
	int cnt = 0;
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		if (needed[i + 1] > cnt || needed[i] >= cnt) {
			ans += cnt - m[i];
			cnt++; // add new line
		}
		else {
			ans += cnt - m[i] - 1;
		}
        // printf("i = %d, cnt = %d\n", i, cnt);
	}
    printf("%lld", ans);
}