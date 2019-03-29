#include <bits/stdc++.h>
using namespace std;
#define pi pair<int, int>

vector<pi> v;
int freq[102], ans, n, k;

void check() {
	for (int i = 0; i < v.size(); i++) {
		if (freq[v[i].first] == 1) {
			ans += max(0, k - v[i].second);
			freq[v[i].first]--;
			v.erase(v.begin() + i);
			if (i > 0 && i < v.size() && v[i - 1].first == v[i].first) {
				freq[v[i].first]--;
				v[i - 1].second += v[i].second;
				v.erase(v.begin() + i);
			}
		}
	}
}

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		if (i == 0 || v[v.size() - 1].first != a) {
			v.push_back(pi(a, 1));
			freq[a]++;
		}
		else
			v[v.size() - 1].second++;
	}
	while (!v.empty()) {
		check();
	}
	printf("%d\n", ans);
}