#include <bits/stdc++.h>
using namespace std;
#define pi pair<int, int>

int a[200005], b[200005];
vector<pi> start;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		string s;
		cin >> s;
		start.clear();
		int n = s.length();
		for (int i = 0; i<n; i++) {
			a[i] = s[i]-'0';
			if (i > 0) {
				if (a[i-1] == 0)
					b[i] = b[i-1] + 1;
				else
					b[i] = 0;
			}
			if (a[i])
				start.push_back(pi(b[i], i));
		}
		sort(start.begin(), start.end(), greater<pi>());
		int ans = 0;
		for (int l = 1; l<=n; l++) {
			int temp = l, k = 0;
			while (temp) {
				temp >>= 1;
				k++;
			}
			int before = l-k;
			for (int i = 0; i<start.size(); i++) {
				if (start[i].first < before)
					break;
				if (start[i].second < before)
					continue;
				if (start[i].second + k > n)
					continue;
				bool good = true;
				for (int j = 0; j<k; j++)
					if (a[start[i].second+k-1-j] != ((l>>j)&1))
						good = false;
				if (good)
					ans++;
			}
		}
		printf("%d\n", ans);
	}
}
