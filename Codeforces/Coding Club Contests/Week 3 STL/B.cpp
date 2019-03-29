#include <bits/stdc++.h>
using namespace std;
#define pi pair<int, int>

pi a[100005];

int main() {
	int n;
    scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a[i].first, &a[i].second);
	}
	sort(a, a + n);
	for (int i = 0; i < n - 1; i++) {
		if (a[i].second > a[i + 1].second) {
			printf("Happy Alex");
			return 0;
		}
	}
	printf("Poor Alex");
}