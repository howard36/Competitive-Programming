#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define cd complex<ld>
#define pl pair<ll, ll>
#define x first
#define y second

pl a[100005];

bool cmp(pl x, pl y) {
	return x.first * y.second < x.second * y.first;
}

double f(pl A, pl B, ll p, ll q) {
	//printf("%lld, %lld - %lld, %lld\n", A.x, A.y, B.x, B.y);
	if (!cmp(B, pl(p, q))) {
		double x = max(1.0*p/B.first, 1.0*q/B.second);
		return x;
		return (ld)max((1.0*p)/B.first, (1.0*q)/B.second);
	}
	if (!cmp(pl(p, q), A)) {
		return max(1.0*p/A.first, 1.0*q/A.second);
	}
	ll a1, a2, b1, b2;
	tie(a1, b1) = A;
	tie(a2, b2) = B;
	return 1.0*((a1-a2)*q - (b1-b2)*p)/(a1*b2 - a2*b1);
}

int main() {
	int n;
	ll p, q;
	scanf("%d %lld %lld", &n, &p, &q);
	int maxA = 0, maxB = 0;
	for (int i = 0; i<n; i++) {
		scanf("%lld %lld", &a[i].first, &a[i].second);
		if (a[i].first > a[maxA].first)
			maxA = i;
		if (a[i].second > a[maxB].second)
			maxB = i;
	}
	sort(a, a+n);
	reverse(a, a+n);
	vector<pl> hull;
	if (n == 1) {
		printf("%.10lf\n", f(a[0], a[0], p, q));
		return 0;
	}
	hull.push_back(a[0]);
	int i = 1;
	while (i < n && a[i].first == a[0].first)
		i++;
	if (i == n) {
		printf("%.10lf\n", f(a[0], a[0], p, q));
		return 0;
	}
	hull.push_back(a[i]);
	i++;
	for (; i<n; i++) {
		pl h1 = hull[hull.size()-1]; 
		pl h2 = hull[hull.size()-2]; 
		if (a[i].first == h1.first)
			continue;
		if (a[i].second <= h1.second)
			continue;
		if ((a[i].y - h1.y) * (h2.x - h1.x) > (a[i].x - h1.x) * (h2.y - h1.y))
			hull.pop_back();
		hull.push_back(a[i]);
	}

	double answ = 1e9;
	for (int i = 0; i<hull.size(); i++) {
		//cout << answ << endl;
		//printf("f = %.10lf\n", f(hull[i], hull[i], p, q));
		answ = min(answ, f(hull[i], hull[i], p, q));
		//printf("hull[%d] = %lld, %lld\n", i, hull[i].x, hull[i].y);
		//printf("ans = %.10lf\n", answ);
	}
	for (int i = 0; i<hull.size()-1; i++) {
		answ = min(answ, f(hull[i], hull[i+1], p, q));
	}
	printf("%.10lf\n", answ);
}
