#include <bits/stdc++.h> 
using namespace std;

vector<int> ch;
vector<int> adj[502];
int dp[102][502], t[102], p[102];

int main() {
	// freopen("data.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	int n, d;
	scanf("%d %d", &n, &d);
	for (int i = 0; i<n; i++){
		scanf("%d %d", &t[i], &p[i]);
		p[i]--;
	}
	for (int i = 0; i<(1<<12); i++) {
		if (__builtin_popcount(i) == d) {
			ch.push_back(i);
		}
	}
	int m = ch.size();
	for (int i = 0; i<m; i++){
		for (int j = 0; j<i; j++){
			if (__builtin_popcount(ch[i]&ch[j]) == d-1){
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}
	for (int i = 0; i<m; i++){
        if ((m>>p[n-1])&1)
		    dp[n-1][i] = 1e9+9;
        else
            dp[n-1][i] = -1;
	}
	for (int i = n-2; i>=0; i--) {
		for (int j = 0; j<m; j++) {
            if (((j>>p[i])&1) == 0){
                dp[i][j] = -1;
                continue;
            }
			if ((ch[j]>>p[i+1])&1) {
				dp[i][j] = dp[i+1][j];
				// printf("Already has bit %d\n", p[i]);
			}
			else {
				dp[i][j] = -1;
				// printf("Doesn't have bit %d\n", p[i]);
			}
			for (int k : adj[j]) {
				if ((ch[k]>>p[i+1])&1) {
					dp[i][j] = max(dp[i][j], min(dp[i+1][k], t[i+1] - t[i]));
					// printf("k = %d, dp %d, t = %d\n", k, dp[i + 1][k], t[i + 1] - t[i]);
				}
			}
			printf("dp[%d][%d] = %d\n", i, j, dp[i][j]);
		}
	}
	int ans = -1;
	for (int i = 0; i<m; i++) {
        if ((ch[i]>>p[0])&1) {
            ans = max(ans, dp[0][i]);
        }
	}
	printf("%d", ans);
}