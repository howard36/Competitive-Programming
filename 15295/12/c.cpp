#include <bits/stdc++.h>
using namespace std;

bool c[5003];
int dp[5003], a[5003], b[5003];

int main() {
	string s;
	cin >> s;
	int n = s.length();
	for (int i = 1; i<n-1; i++) {
		c[i] = (s[i-1] == s[i+1]);
	}
	for (int i = 1; i<n; i++) {
		set<int> S;
		for (int j = 0; j<i; j++) {
			S.insert(dp[max(0, j-1)] ^ dp[max(0, i-j-2)]);
		}
		while (!S.empty() && *S.begin() == dp[i]) {
			S.erase(S.begin());
			dp[i]++;
		}
	}
	int ans = 0;
	for (int i = 1; i<n; i++) {
		if (!c[i]) {
			a[i] = 0;
			ans ^= dp[a[i-1]];
		}
		else
			a[i] = a[i-1] + 1;
	}
	if (ans == 0) {
		cout << "Second" << endl;
		return 0;
	}
	else
		cout << "First" << endl;

	for (int i = n-2; i>0; i--) {
		if (!c[i]) 
			b[i] = 0;
		else
			b[i] = b[i+1] + 1;
	}
	for (int i = 1; i<n-1; i++) {
		if (c[i] && (ans ^ dp[a[i]+b[i]-1] ^ dp[max(0, a[i]-2)] ^ dp[max(0, b[i]-2)]) == 0) {
			cout << i+1 << endl;
			return 0;
		}
	}
}
