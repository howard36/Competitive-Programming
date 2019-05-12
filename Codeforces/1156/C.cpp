#include <bits/stdc++.h>
using namespace std;

int a[200005];
multiset<int> s;

int main() {
	int n, z;
	scanf("%d %d", &n, &z);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		s.insert(-a[i]);
	}
	int ans = 0;
	while (s.size()) {
		int lo = *s.begin();
		auto it = s.lower_bound(lo + z);
		if (it == s.end()) {
            break;
		}
		else {
            // printf("%d-%d\n", lo, *it);
			s.erase(it);
			s.erase(s.begin());
			ans++;
		}
	}
    printf("%d", ans);
}