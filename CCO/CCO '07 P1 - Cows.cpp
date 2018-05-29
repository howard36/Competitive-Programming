#include <vector>
#include <algorithm>
#include <complex>
#include <cstdio>
#include <cmath>
#define cd complex<double>
#define pi pair<int,int>
#define x first
#define y second
using namespace std;

bool CompareAngle(cd a, cd b) {
	return arg(a / b) < 0;
}

bool CompareImag(cd a, cd b) {
	return imag(a) < imag(b) || (imag(a) == imag(b) && real(a) < real(b));
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
		while (arg((a - b) / (c - b)) <= 0) {  // If angle ABC is concave, remove B
			hull.pop_back();
			a = hull[hull.size() - 2];
			b = hull[hull.size() - 1];
		}
		hull.push_back(c);
	}

	return hull;
}

double shoelace(vector<cd> points)
{
	points.push_back(points[0]); // to form a loop
	double sum = 0;
	for (int i = 0; i < points.size() - 1; i++)
		sum += real(points[i]) * imag(points[i + 1]);
	for (int i = 0; i < points.size() - 1; i++)
		sum -= imag(points[i]) * real(points[i + 1]);
	double area = abs(sum) / 2;
	return area;
}

int main()
{
	int n, x, y;
	double xd, yd;
	vector<cd> points;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &x, &y);
		xd = 1.0*x, yd = 1.0*y;
		points.push_back(cd(xd, yd));
	}
	vector<cd> hull = ConvexHull(points);
	double area = shoelace(hull);
	int ans = (int)floor(area/50);
	printf("%d", ans);
    return 0;
}