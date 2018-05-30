#include <cstdio>
#include <complex>
#include <vector>
#include <algorithm>
#define cd complex<double>
using namespace std;

cd points[100005];

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

int main()
{
	int N; double x, y;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%lf %lf", &x, &y);
		points[i] = cd(x, y);
	}
	double minradius = 1e9;
	for (int i = 0; i < N; i++) {
		vector<cd> inverted;
		for (int j = 0; j < N; j++) {
			if (i == j)
				continue;
			inverted.push_back(conj(cd(1,0) / (points[j] - points[i])) + points[i]);
		}
		vector<cd> hull = ConvexHull(inverted);
		cd mid = cd(0, 0);
		for (cd& p : inverted)
			mid += p;
		mid /= N - 1;
		hull.push_back(hull[0]);
		for (int j = 1; j < hull.size(); j++) {
			if (real((points[i] - hull[j]) / (hull[j - 1] - hull[j]))*real((mid - hull[j]) / (hull[j - 1] - hull[j])) > 0) {
				if (abs(1 / (2 * real((points[i] - hull[j]) / (hull[j - 1] - hull[j]))*abs(hull[j - 1] - hull[j]))) < minradius) {
					minradius = abs(1 / (2 * real((points[i] - hull[j]) / (hull[j - 1] - hull[j]))*abs(hull[j - 1] - hull[j])));
				}
			}
		}
	}
	printf("%.9lf", minradius);
    return 0;
}