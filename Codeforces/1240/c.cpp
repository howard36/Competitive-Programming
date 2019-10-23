#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int, int>
#define ppi pair<ll, pi>

ppi edges[500005];
int deg[500005];

int main() {
	int q;
	scanf("%d", &q);
	while (q--) {
		int n, k;
		scanf("%d %d", &n, &k);
		memset(deg, 0, sizeof deg);
		for (int i = 0; i<n-1; i++) {
			int a, b;
			ll w;
			scanf("%d %d %lld", &a, &b, &w);
			edges[i] = ppi(w, pi(a, b));
		}
		sort(edges, edges+n-1);
		reverse(edges, edges+n-1);
		ll ans = 0;
		for (int i = 0; i<n-1; i++) {
			int a, b;
			tie(a, b) = edges[i].second;
			if (deg[a] == k || deg[b] == k)
				continue;
			deg[a]++;
			deg[b]++;
			ans += edges[i].first;
		}
		printf("%lld\n", ans);
	}
}
