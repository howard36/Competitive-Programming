#include <bits/stdc++.h>
#define cd complex<double>
#define pnt pair<double, cd>
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
		while (imag((a - b) / (c - b)) <= 0) {  // If angle ABC is concave, remove B
			hull.pop_back();
			a = hull[hull.size() - 2];
			b = hull[hull.size() - 1];
		}
		hull.push_back(c);
	}

	return hull;
}

void AddPoint(set<pnt>& hull, cd point) { // needs bbst with log(n) kth element search using custom comparator, instead of set
	int n = hull.size();
	if (n < 2) {
		hull.insert(pnt(n, point));
		return;
	}
	cd first = (*(hull.begin())).second;
	cd last = (*(hull.end())).second;
	cd O = (first + last) / 2.0;
	int under, over;
	if (arg((point - last)/(first - last)) <= 0) {
		under = n;
		over = 0;
	} else {
		under = 12345; // get the index (sorted by angle from O) that point would be at if it was inserted into the set using bbst kth element
		over = under + 1;
	}
	// compare angle point, under, under - 1. If concave, remove under and do under--
}
