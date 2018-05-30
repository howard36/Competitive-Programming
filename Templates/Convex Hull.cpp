#include <bits/stdc++.h>
#define cd complex<double>
using namespace std;

bool CompareAngle(cd a, cd b) {
	return arg(a / b) < 0;
}

bool CompareImag(cd a, cd b) {
	return imag(a) < imag(b) || (imag(a) == imag(b) && abs(a) < abs(b));
}

vector<cd> ConvexHull(vector<cd> points) {
	if (points.size() <= 3)
		return points;
	sort(points.begin(), points.end(), CompareImag);
	cd O = points[0];
	for (cd &p : points)
		p -= O;
	sort(points.begin() + 1, points.end(), CompareAngle);
	for (cd &p : points)
		p += O;

	vector<cd> hull{ points[0], points[1] };
	for (int i = 2; i < points.size(); i++) {
		cd a = hull[hull.size() - 2];
		cd b = hull[hull.size() - 1];
		cd c = points[i];
		while (arg((a - b) / (c - b)) <= 1e-5) {  // If angle ABC is concave, remove B
			hull.pop_back();
			a = hull[hull.size() - 2];
			b = hull[hull.size() - 1];
		}
		hull.push_back(c);
	}

	return hull;
}
