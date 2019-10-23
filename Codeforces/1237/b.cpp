#include <bits/stdc++.h>
using namespace std;

int bit[100005];

void update(int i) {
	for (; i<100005; i+=(i&-i))
		bit[i]++;
}

bool query(int i) {
	for (; i>0; i-=(i&-i)) {
		if (bit[i])
			return true;
	}
	return false;
}

int ord[100005], p[100005];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i<=n; i++) {
		int x;
		scanf("%d", &x);
		ord[x] = i;
	}
	for (int i = 1; i<=n; i++) {
		int x;
		scanf("%d", &x);
		p[i] = ord[x];
	}
	int ans = 0;
	for (int i = n; i>0; i--) {
		if (query(p[i]))
			ans++;
		update(p[i]);
	}
	printf("%d", ans);
}
