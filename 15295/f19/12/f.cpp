#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int, int>
 
vector<int> v;
 
int main() {
	int q;
	scanf("%d", &q);
	while (q--) {
		int a, b;
		string s;
		scanf("%d %d", &a, &b);
		cin >> s;
		int n = s.length();
		int cur = 0;
		v.clear();
		for (int i = 0; i<n; i++) {
			if (s[i] == '.')
				cur++;
			else {
				if (cur >= b)
					v.push_back(cur);
				cur = 0;
			}
		}
		if (cur >= b)
			v.push_back(cur);
		sort(v.begin(), v.end());
		if (v.size() == 0) {
			printf("NO\n");
			continue;
		}
		if (v[0] < a) {
			printf("NO\n");
			continue;
		}
		// all L >= a
		if (v.size() == 1) {
			int L = v[v.size()-1];
			if (L <= a + 2*b - 2) {
				printf("YES\n");
				continue;
			}
			else if (L >= 3*a && L <= a + 4*b - 2) {
				printf("YES\n");
				continue;
			}
			else {
				printf("NO\n");
				continue;
			}
		}
		if (v[v.size()-2] >= 2*b) {
			printf("NO\n");
			continue;
		}
		// at most one L >= 2*b
		int L = v[v.size()-1];
		if (v.size()%2 == 1) {
			if (L <= a + 2*b - 2) {
				printf("YES\n");
				continue;
			}
			else if (L >= 3*a && L <= a + 4*b - 2) {
				printf("YES\n");
				continue;
			}
			else {
				printf("NO\n");
				continue;
			}
		}
		else {
			// misere
			if (L < 2*a) {
				printf("NO\n");
				continue;
			}
			if (L <= a + 3*b - 2) {
				printf("YES\n");
				continue;
			}
			else {
				printf("NO\n");
				continue;
			}
		}
	}
}
