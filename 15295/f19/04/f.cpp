#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int, int>

int a[200005], f[200005], b[200005];
map<int, int> m;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i<n; i++) {
		scanf("%d", &a[i]);
		b[i] = a[i];
	}
	sort(b, b+n);
	int num = unique(b, b+n) - b;
	for (int i = 0; i<num; i++) {
		m[b[i]] = i;
	}
	int has = 0, r = 0, ans = 0, works = 0;
	for (int i = 0; i<n; i++) {
		while (has < num && r < n) {
			if (f[m[a[r]]] == 0)
				has++;
			f[m[a[r]]]++;
			r++;
		}
		if (has == num) {
			ans = max(ans, r-i);
			works = i;
		}
		f[m[a[i]]]--;
		if (f[m[a[i]]] == 0)
			has--;
	}
	printf("%d", max(ans, n-works));
}
