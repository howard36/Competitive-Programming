#include <bits/stdc++.h>
#define pi pair<int, int>
using namespace std;

int l[200005], r[200005];
int earlyR[200005], lateL[200005];
pi L[200005], R[200005];

int main() {
	int n;
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &l[i], &r[i]);
		L[i] = pi(l[i], i), R[i] = pi(r[i], i);
	}
	sort(L, L + n, greater<pi>());
	sort(R, R + n);
	int t = 0, lastR = 0;
	for (int i = 0; i < n; i++) {
		while (l[R[t].second] <= lastR) t++;
        earlyR[i] = R[t].second, early[t] = i;
	}
}