#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define cd complex<ld>
#define pi pair<ld, int>
#define pl pair<ll, ll>
const ld PI = acos((ld)(-1.0));

pi a[100005];
pl p[100005];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i<n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		a[i] = pi(arg(cd((ld)x, (ld)y)), i+1);
	}
	sort(a, a+n);
	a[n] = a[0];
	ld ans = 100;
	int best = 0;
	for (int i = 0; i<n; i++) {
		ld x = abs(a[i+1].first-a[i].first);
		if (x > PI)
			x = 2*PI - x;
		if (x < ans) {
			ans = x;
			best = i;
		}
	}
	printf("%d %d\n", a[best].second, a[best+1].second);
}
