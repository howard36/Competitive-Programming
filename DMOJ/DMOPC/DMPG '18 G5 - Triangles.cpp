#include <vector>
#include <algorithm>
#include <complex>
#include <cstdio>
#define cd complex<double>
using namespace std;

vector<cd> Points, Hull;
int H;

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

inline double Dist(int p, int a, int b) {
	p %= H; a %= H; b %= H;
	return abs(imag((Hull[p] - Hull[a]) / (Hull[b] - Hull[a]))*abs((Hull[b] - Hull[a])));
}

double MaxDist(int l, int r) {
	int L = l, R = r;
	while (r - l > 2) {
		int mid = (r + l) / 2;
		double d1 = Dist(mid-1, L, R);
		double d2 = Dist(mid, L, R);
		double d3 = Dist(mid+1, L, R);
		if (d1 <= d2 && d2 >= d3)
			return d2;
		else if (d1 <= d2 && d2 <= d3)
			l = mid + 1;
		else
			r = mid - 1;
	}
	double m = 0;
	for (int i = l; i <= r; i++) {
		m = max(m, Dist(i, L, R));
	}
	return m;
}

int main()
{
	int N;
	double x, y;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%lf %lf", &x, &y);
		Points.push_back(cd(x, y));
	}
	Hull = ConvexHull(Points);

	H = Hull.size();
	double maxArea = 0;
	for (int i = 0; i < H; i++) {
		for (int j = i + 1; j < H; j++) {
			double d1 = MaxDist(i, j);
			double d2 = MaxDist(j, i + H);
			double area = abs(Hull[i] - Hull[j])*max(d1, d2) / 2;
			if (area > maxArea)
				maxArea = area;
		}
	}
	printf("%lf\n", maxArea);
    return 0;
}