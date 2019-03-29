#include <bits/stdc++.h>
using namespace std;

vector<int> candy[5003];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		candy[a].push_back((b - a + n) % n);
	}
	for (int i = 1; i <= n; i++) {
		sort(candy[i].begin(), candy[i].end());
	}
	for (int i = 1; i <= n; i++) {
		int ans = 0;
		for (int j = 1; j <= n; j++) {
			if (candy[j].size())
				ans = max(ans, (j - i + n) % n + n * ((int)candy[j].size() - 1) + candy[j][0]);
		}
        printf("%d ", ans);
	}
}