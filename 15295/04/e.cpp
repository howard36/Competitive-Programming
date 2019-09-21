#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int, int>

set<pi> s;
pi a[200005];

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i<n; i++) {
		scanf("%d %d", &a[i].second, &a[i].first);
	}
	sort(a, a+n);
	int ptr = 0, stars = 0;
	ll t = 0;
	while (stars < k) {
		while (ptr < n && a[ptr].first <= stars) {
			s.insert(pi(a[ptr].second, ptr));
			ptr++;
		}
		if (s.empty())
			break;
		t += s.begin()->first;
		s.erase(s.begin());
		stars++;
	}
	if (stars < k)
		printf("IMPOSSIBLE");
	else
		printf("%lld", t);
}
