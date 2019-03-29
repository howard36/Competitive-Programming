#include <bits/stdc++.h>
using namespace std;
#define pi pair<int, int>
#define ll long long

pi h[1000006];
multiset<int> s;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &h[i].first, &h[i].second);
	}
	sort(h, h + n, greater<pi>());
	int ptr = 0;
	ll ans = 0;
	for (int t = 1000000; t > 0; t--) {
		while (ptr < n && h[ptr].first == t) {
			s.insert(h[ptr].second);
			ptr++;
		}
		if (!s.empty()) {
			int hi = *s.rbegin();
            ans += hi;
            auto it = s.find(hi);
            s.erase(it);
		}
	}
    printf("%lld", ans);
}