#include <bits/stdc++.h>
using namespace std;

int f[300005], l[300005], a[300005];
int bit[300005];

int query(int i) {
	assert(i > 0);
	int ans = 0;
	for (; i>0; i-=(i&-i))
		ans = max(ans, bit[i]);
	return ans;
}

void update(int i, int val) {
	assert(i > 0);
	for (; i<300005; i+=(i&-i))
		bit[i] = max(bit[i], val);
}

int main() {
	int q;
	scanf("%d", &q);
	while (q--) {
		int n;
		scanf("%d", &n);
		memset(f, -1, sizeof f);
		memset(l, -1, sizeof l);
		memset(bit, 0, sizeof bit);
		for (int i = 1; i<=n; i++) {
			scanf("%d", &a[i]);
			l[a[i]] = i;
		}
		for (int i = n; i>0; i--)
			f[a[i]] = i;
		vector<int> v;
		for (int i = 1; i<=n; i++) {
			if (f[i] != -1)
				v.push_back(i);
		}
		for (int i : v) {
			int length = query(f[i]) + 1;
			update(l[i], length);
		}
		printf("%d\n", v.size()-query(300001));
	}
}
