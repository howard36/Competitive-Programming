#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define cd complex<ld>

int r[1000];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i<n; i++) {
		scanf("%d", &r[i]);
	}
	sort(r, r+n);
	reverse(r, r+n);
	int ans = 0;
	for (int i = 0; i<n; i++) {
		if (i%2 == 0)
			ans += r[i]*r[i];
		else
			ans -= r[i]*r[i];
	}
	cout << 3.1415926536 * ans << endl;

}
