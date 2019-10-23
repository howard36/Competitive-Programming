#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<ll, ll>

int a[300005];
deque<int> q;

int main() {
	int n;
	scanf("%d", &n);
	int m = 1e9, M = 0;
	for (int i = 0; i<n; i++) {
		scanf("%d", &a[i]);
		a[i+n] = a[i];
		a[i+2*n] = a[i];
		m = min(a[i], m);
		M = max(a[i], M);
	}
	if (2*m >= M) {
		for (int i = 0; i<n; i++)
			printf("-1 ");
		printf("\n");
		return 0;
	}
	for (int i = 0; i<n; i++) {
		int j = i+1;
		if (i > 0 && a[c[i-1]]) {
			c[i] = c[i-1] - 1;
			continue;
		}
		while (j<3*n && a[j]) {
			
		
	}
}
