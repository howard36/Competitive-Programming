#include <bits/stdc++.h>
using namespace std;

int num[100005][26];
int cur[100005], used[100005];

string s[1000006];
int ans[1000006], length;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		for (int j = 0; j < s[i].length(); j++) {
			num[i][s[i][j] - 'a']++;
		}
	}
	for (int i = 25; i >= 0; i--) {
		int minCount = 1e9;
		for (int j = 0; j < n; j++) {
			minCount = min(minCount, num[j][i]);
		}
		if (minCount == 0)
			continue;
		for (int j = 0; j < n; j++) {
            int origNum = num[j][i];
            while (num[j][i] > origNum - minCount){
                num[j][s[j][cur[j]]-'a']--;
                cur[j]++;
            }
		}
		for (int j = 0; j < minCount; j++) {
			ans[length + j] = i;
		}
		length += minCount;
	}
	if (length == 0) {
		printf("-1\n");
	}
	else {
		for (int i = 0; i < length; i++) {
			printf("%c", 'a' + ans[i]);
		}
		printf("\n");
	}
}