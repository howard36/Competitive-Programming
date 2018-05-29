#include <cstdio>
#include <complex>
#include <vector>
#include <algorithm>
#define pt complex<double>
#define circle pair<double, pt>
using namespace std;

vector<pt> points;
vector<double> radii;

circle circumcircle(pt a, pt b, pt c) {
	if (abs(a-b) < 1e-8 || abs(b - c) < 1e-8 || abs(c - a) < 1e-8)
		return circle(-1.0, pt(0, 0));
	pt x = (a - b) / (a - c);
	if (abs(x - conj(x)) < 1e-8)
		return circle(-1.0, pt(0, 0));
	a -= c;
	b -= c;
	pt O = c + a * b*(conj(a) - conj(b)) / (conj(a)*b - a * conj(b));
	double r = abs(O - c);
	return circle(r, O);
}

bool check(circle C) {
	double r = C.first;
	pt O = C.second;
	bool good = true;
	for (pt p : points) {
		if (abs(p - O) > r + 1e-8)
			good = false;
	}
	return good;
}

int main()
{
	int N, x, y;
	scanf("%d", &N);
	if (N == 1) {
		printf("0");
		return 0;
	}
	for (int i = 0; i < N; i++) {
		scanf("%d%d", &x, &y);
		points.push_back(pt(1.0*x, 1.0*y));
	}
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			for (int k = j + 1; k < N; k++) {
				circle C = circumcircle(points[i], points[j], points[k]);
				if (C.first >= 0 && check(C)) {
					radii.push_back(C.first);
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			pt a = points[i];
			pt b = points[j];
			circle C = circle(abs(a-b)/2, (a+b)/pt(2,0));
			if (check(C))
				radii.push_back(C.first);
		}
	}
	sort(radii.begin(), radii.end());
	printf("%.10lf", radii[0]);
    return 0;
}