#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int, int>

ll a[1003][1003], b[1003];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++) {
			scanf("%lld", &a[i][j]);
		}
	}
	b[0] = (ll)sqrt(a[0][1] * a[2][0] / a[2][1]);
	printf("%lld ", b[0]);
	for (int i = 1; i<n; i++) {
		printf("%lld ", a[0][i] / b[0]);
	}
}
