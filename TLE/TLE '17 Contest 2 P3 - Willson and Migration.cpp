#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
#define point pair<double,double>

void loop(bool b){
    if (b)
        while (true) {}
}

struct path
{
	double x1, y1, x2, y2, v;
	path() : x1(), y1(), x2(), y2(), v() {}
	path(double a, double b, double c, double d, double e) : x1(a), y1(b), x2(c), y2(d), v(e) {}
};

path paths[10004];
/*
double slope(path p)
{
	return (p.y1 - p.y2) / (p.x1 - p.x2);
}

point intersect(path a, path b)
{
	if (a.x1 == a.x2)
	{
		if (b.x1 == b.x2)
			return point(123456, 123456);
		return point(a.x1, slope(b)*(a.x1 - b.x1) + b.y1);
	}
	if (b.x1 == b.x2)
		return point(b.x1, slope(a)*(b.x1 - a.x1) + a.y1);

	double ma = slope(a), mb = slope(b);
	if (abs(ma-mb) < 1e-5)
		return point(123456, 123456);

	double x = (ma*a.x1 - mb*b.x1 - a.y1 + b.y1) / (ma - mb);
	double y = ma * (x - a.x1) + a.y1;
	return point(x, y);
}*/

double dist(double x1, double y1, double x2, double y2)
{
	return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

double minDist(path a, path b)
{
	/*
	point p = intersect(a, b);
	if (p.first == 123456 && p.second == 123456)
	{
		return -1;
	}
	double da = dist(a.x1, a.y1, p.first, p.second);
	double db = dist(b.x1, b.y1, p.first, p.second);
	double c = ((a.x2 - a.x1)*(b.x2 - b.x1) + (a.y2 - a.y1)*(b.y2 - b.y1)) / (dist(a.x1, a.y1, a.x2, a.y2)*dist(b.x1, b.y1, b.x2, b.y2));
	double A = a.v*a.v + b.v*b.v - 2 * a.v*b.v*c;
	double B = 2 * (da*b.v*c + db*a.v*c - da*a.v - db*b.v);
	double C = da*da + db*db - 2 * da*db*c;

	double x = -B / (2 * A);
	if (x < 0)
		return C;
	else
		return A*x*x + B*x + C;
		*/
	double da = dist(a.x1, a.y1, a.x2, a.y2);
	double db = dist(b.x1, b.y1, b.x2, b.y2);
	double x1 = a.x1 - b.x1, x2 = a.v*(a.x2 - a.x1) / da - b.v*(b.x2 - b.x1) / db;
	double y1 = a.y1 - b.y1, y2 = a.v*(a.y2 - a.y1) / da - b.v*(b.y2 - b.y1) / db;
	double A = x2*x2 + y2*y2;
	double B = 2 * x1*x2 + 2 * y1*y2;
	double C = x1*x1 + y1*y1;
	
	loop(abs(A) < 1e-4 && abs(B) > 1e-4);
	loop(A < 0);
	double t = -B / (2 * A);
	if (abs(A) < 1e-4 && abs(B) < 1e-4)
	{
	    loop(abs((a.x2 - a.x1) / da - (b.x2 - b.x1) / db) > 1e-4);
	    return sqrt(C);
	}
	if (t < 0)
		return sqrt(C);
	else
		return sqrt(A*t*t + B*t + C);
}

int main()
{
	int N, R;
	scanf("%d %d", &N, &R);
	for (int i = 1; i <= N; i++)
		scanf("%lf %lf %lf %lf %lf", &paths[i].x1, &paths[i].y1, &paths[i].x2, &paths[i].y2, &paths[i].v);
	for (int i = 2; i <= N; i++)
	{
		if (minDist(paths[1], paths[i]) < R + 1e-4)
			printf("%d\n", i);
	}
    return 0;
}