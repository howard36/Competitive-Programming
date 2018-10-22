#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll prefix[100005];
vector<ll> pos[2];

ll join(int l, int t) {
	ll best = 1e18;
	for (int mid = l / 2; mid <= pos[t].size() - (l + 1) / 2; mid++) {
		ll m = pos[t][mid];
		best = min(best, (m * (m - 1) / 2 - (m - l / 2) * (m - l / 2 - 1) / 2) -
							 (prefix[mid] - prefix[mid - l / 2]) +
							 (prefix[mid + (l + 1) / 2] - prefix[mid]) -
							 ((m + (l + 1) / 2) * (m + (l + 1) / 2 - 1) / 2 -
							  m * (m - 1) / 2));
	}
	return best;
}

int main() {
	int n, k;
	char c;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf(" %c", &c);
		if (c == '1')
			pos[1].push_back(i);
		else
			pos[0].push_back(i);
	}
	for (int i = 0; i < pos[1].size(); i++) {
		prefix[i + 1] = prefix[i] + pos[1][i];
	}
	int lo = 0, hi = pos[1].size();
	while (lo < hi) {
		int mid = (lo + hi + 1) / 2;
		if (join(mid, 1) <= k) {
			lo = mid;
		}
		else {
			hi = mid - 1;
		}
	}
	printf("%d ", lo);
	for (int i = 0; i < pos[0].size(); i++) {
		prefix[i + 1] = prefix[i] + pos[0][i];
	}
	lo = 0, hi = pos[0].size();
	while (lo < hi) {
		int mid = (lo + hi + 1) / 2;
		if (join(mid, 0) <= k) {
			lo = mid;
		}
		else {
			hi = mid - 1;
		}
	}
	printf("%d", lo);
}