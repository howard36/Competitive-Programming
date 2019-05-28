#include <bits/stdc++.h>
using namespace std;

int a[200005], dp[200005], last[200005], use[200005];

int main() {
	int n;
	char c;
	scanf("%d", &n);
	memset(last, -1, sizeof last);
	for (int i = 0; i < n; i++) {
		scanf(" %c", &c);
		a[i] = c - 'a';
	}
	last[0] = -1;
	int cnt = 1;
	for (int i = 1; i < n; i++) {
		if (a[i] != a[i - 1]) {
			last[i] = i - 1;
			cnt = 1;
		}
		else {
			last[i] = i - cnt - 1;
			cnt++;
		}
	}
	dp[0] = 0;
	for (int i = 1; i < n; i++) {
		dp[i] = dp[i - 1];
		if (last[i] == -1)
			use[i] = 0;
		else if (last[i] == 0) {
			if (1 > dp[i]) {
				dp[i] = 1;
				use[i] = 1;
			}
		}
		else {
			if (1 + dp[last[i] - 1] > dp[i]) {
				dp[i] = 1 + dp[last[i] - 1];
				use[i] = 1;
			}
		}
	}
	// for (int i = 0; i < n; i++) {
	// 	printf("dp[%d] = %d\n", i, dp[i]);
	// }
	printf("%d\n", n - dp[n - 1] * 2);
    vector<int> s;
    int p = n-1;
    while (p >= 0){
        if (use[p]){
            s.push_back(a[p]);
            s.push_back(a[last[p]]);
            p = last[p]-1;
        }
        else {
            p--;
        }
    }
    reverse(s.begin(), s.end());
    for (int i = 0; i<s.size(); i++){
        printf("%c", s[i]+'a');
    }
}