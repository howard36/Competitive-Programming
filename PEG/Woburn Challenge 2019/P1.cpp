#include <bits/stdc++.h>
using namespace std;

int e[3], a[1003], diff[1003];

int main() {
	for (int i = 0; i < 3; i++) {
		scanf("%d", &e[i]);
	}
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		a[i]--;
	}
	diff[n-1] = (a[n - 1] + 1) % 3;
	for (int i = n - 2; i >= 0; i--) {
		if (a[i] == a[i + 1])
			diff[i] = diff[i + 1];
		else
			diff[i] = (6 - a[i] - a[i + 1]) % 3;
	}
    int ans = 0;
    for (int i = 0; i<n; i++){
        ans += e[a[i]];
        e[diff[i]] += e[a[i]];
        e[a[i]] = 0;
    }
    printf("%d", ans);
}