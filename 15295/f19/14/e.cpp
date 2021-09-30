#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define cd complex<long double>
#define pd pair<cd, int>
#define pi pair<ll, ll>
#define ppi pair<pi, int>
#define x first
#define y second

cd p[2003];
pd P[2003];

bool cmp(pd a, pd b) {
	cd A = a.first, B = b.first;
	if (abs(arg(A) - arg(B)) > 1e-7 && abs(arg(A) - arg(B)) < 2*acos(-1))
		return arg(A) < arg(B);
	return abs(A) < abs(B);
}
/*
bool cmp2(ppi a, ppi b) {
	pi A = a.first, B = b.first;
	if (B.y == 0) {
		if (B.y > 0)
}*/

int main() {
	int c;
	cin >> c;
	while (c--) {
		int n;
		cin >> n;
		for (int i = 0; i<n; i++) {
			double x, y;
			cin >> x >> y;
			p[i] = cd(x,y);
		}
		for (int i = 1; i<n; i++)
			P[i] = pd(p[i]-p[0], i);
		sort(P+1, P+n, cmp);
		cout << "0 ";
		for (int i = 1; i<n; i++)
			cout << P[i].second << " ";
		cout << endl;
	}
}
