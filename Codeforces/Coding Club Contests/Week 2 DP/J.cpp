#include <bits/stdc++.h>
using namespace std;
#define pi pair<int, int>
#define ppi pair<int, pi>

struct item {
	int t, d, p, idx;
} a[102];
pi dp[102][2023];

bool comp(item x, item y) {
	return x.d < y.d;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &a[i].t, &a[i].d, &a[i].p);
		a[i].idx = i + 1;
	}
	sort(a, a + n, comp);
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < 2003; j++) {
			dp[i][j] = pi(dp[i + 1][j].first, 0);
			if (j + a[i].t < a[i].d) {
				if (dp[i + 1][j + a[i].t].first + a[i].p > dp[i][j].first) {
					dp[i][j] = pi(dp[i + 1][j + a[i].t].first + a[i].p, 1);
				}
			}
		}
	}
	printf("%d\n", dp[0][0].first);
	vector<int> ans;
    int t = 0;
    for (int i = 0; i < n; i++){
        if (dp[i][t].second){
            ans.push_back(a[i].idx);
            t += a[i].t;
        }
    }
	printf("%d\n", (int)ans.size());
	for (int i = 0; i < ans.size(); i++) {
		printf("%d ", ans[i]);
	}
}