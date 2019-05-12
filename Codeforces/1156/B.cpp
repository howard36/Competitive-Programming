#include <bits/stdc++.h>
using namespace std;
// #define pi pair<int, int>

int freq[30];
vector<int> start, back, mid;

int main() {
    // freopen("data.txt", "r", stdin);
    // printf("Hi");
	int t;
    scanf("%d", &t);
	while (t--) {
		string s;
		cin >> s;
		int n = s.length();
		memset(freq, 0, sizeof freq);
        start.clear();
        mid.clear();
        back.clear();
		int m = 26, M = -1;
		for (int i = 0; i<n; i++) {
            int c = s[i]-'a';
			freq[c]++;
			m = min(m, c);
			M = max(M, c);
		}
		if (M - m == 1 || ((M - m == 2) && freq[m + 1])) {
			printf("No answer\n");
			continue;
		}
		int l = -101, r = -100;
		for (int i = 0; i <= 26; i++) {
			if (freq[i] == 0) {
				if (r == i - 1) {
					if (l == r)
						mid.push_back(l);
					else {
						for (int j = l; j <= r; j++) {
							if ((j - l) % 2 == 0)
								start.push_back(j);
							else
								back.push_back(j);
						}
					}
				}
				continue;
			}
			if (i != 0 && freq[i - 1])
				r = i;
			else {
				l = r = i;
			}
		}
		reverse(start.begin(), start.end());
		reverse(back.begin(), back.end());
		for (int i : start) {
			for (int j = 0; j < freq[i]; j++) {
				printf("%c", 'a' + i);
			}
		}
		for (int i : mid) {
			for (int j = 0; j < freq[i]; j++) {
				printf("%c", 'a' + i);
			}
		}
		for (int i : back) {
			for (int j = 0; j < freq[i]; j++) {
				printf("%c", 'a' + i);
			}
		}
		printf("\n");
	}
}