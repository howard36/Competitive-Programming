#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> sizes;

int a[3003][3003];
int sparse[2][3003][3003];

int main() {
	int n, K;
	scanf("%d %d", &n, &K);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {
			scanf("%d", &a[i][j]);
		}
	}

	for (int t = K; t; t = (2 * t + 1) / 3) {
		sizes.push_back(t);
		if (t == 1)
			break;
	}
	reverse(sizes.begin(), sizes.end());

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {
			sparse[0][i][j] = a[i][j];
		}
	}
	for (int k = 1; k < sizes.size(); k++) {
		int s1 = sizes[k];
		int s2 = sizes[k - 1];
		for (int i = 0; i < n - s1 + 1; i++) {
			for (int j = 0; j < i + 1; j++) {
				sparse[k & 1][i][j] = max(sparse[(k ^ 1) & 1][i][j], max(sparse[(k ^ 1) & 1][i + s1 - s2][j], sparse[(k ^ 1) & 1][i + s1 - s2][j + s1 - s2]));
			}
		}
	}

	ll ans = 0;
	for (int i = 0; i < n - K + 1; i++) {
		for (int j = 0; j < i + 1; j++) {
			ans += (ll)sparse[(sizes.size() - 1) & 1][i][j];
		}
	}
	printf("%lld", ans);
}