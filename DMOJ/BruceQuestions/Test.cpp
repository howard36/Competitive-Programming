#include <bits/stdc++.h>
using namespace std;
#define pi pair<int, int>

pi a[1000005];
vector<pi> up, down;

bool upcomp(pi x, pi y) {
	if (x.first != y.first)
		return x.first < y.first;
	return x.second > y.second;
}

bool downcomp(pi x, pi y) {
	if (x.second != y.second)
		return x.second > y.second;
	return x.first < y.first;
}

int main() {
	// freopen("data.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		int m = s.length(), cur = 0;
		for (int j = 0; j < m; j++) {
			if (s[j] == '(') {
				cur++;
			}
			else {
				if (cur == 0)
					a[i].first++;
				else
					cur--;
			}
			// printf("j = %d, cur = %d\n", j, cur);
		}
		a[i].second = cur;
        printf("i = %d, (%d, %d)\n", i, a[i].first, a[i].second);
		ans += m - a[i].first - a[i].second;
		if (a[i].first < a[i].second)
			up.push_back(a[i]);
		else
			down.push_back(a[i]);
	}
	// printf("%d %d\n", a[0].first, a[0].second);
	// printf("%d\n", ans);
	sort(up.begin(), up.end(), upcomp);
	sort(down.begin(), down.end(), downcomp);
	up.insert(up.end(), down.begin(), down.end());
    // printf("Sorted: \n");
    // for (int i = 0; i<up.size(); i++){
    //     printf("(%d %d)\n", up[i].first, up[i].second);
    // }
	int cur = 0;
	for (int i = 0; i < up.size(); i++) {
		ans += 2 * min(cur, up[i].first);
		cur -= min(cur, up[i].first);
		cur += up[i].second;
	}
	printf("%d", ans);
}