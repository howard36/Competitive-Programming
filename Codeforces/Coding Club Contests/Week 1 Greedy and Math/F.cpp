#include <bits/stdc++.h>
using namespace std;
#define pi pair<int, int>

int p[6], numtochar[10], lead[10];
pi w[10];

int main() {
	int n;
	scanf("%d", &n);
	p[0] = 1;
	for (int i = 1; i < 6; i++) {
		p[i] = 10 * p[i - 1];
	}
	for (int i = 0; i < 10; i++) {
		w[i].second = i;
        numtochar[i] = -1;
	}
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		int m = s.length();
		for (int j = 0; j < m; j++) {
			w[s[j] - 'a'].first += p[m - j - 1];
		}
		lead[s[0] - 'a'] = 1;
	}
	sort(w, w + 10, greater<pi>());
    int ans = 0;
	for (int i = 0; i < 10; i++) {
        int c = w[i].second;
        for (int j = lead[c]; j<10; j++){
            if (numtochar[j] == -1){
                numtochar[j] = c;
                ans += j * w[i].first;
                break;
            }
        }
	}
    printf("%d", ans);
}