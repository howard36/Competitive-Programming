#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

struct vector3
{
	double x, y, z;
	vector3() : x(), y(), z() {}
	vector3(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {}
};

struct triangle
{
	vector3 a, b, c;
	triangle() : a(), b(), c() {}
	triangle(vector3 _a, vector3 _b, vector3 _c) : a(_a), b(_b), c(_c) {}
};

vector3 add(vector3 a, vector3 b)
{
	return vector3(a.x + b.x, a.y + b.y, a.z + b.z);
}

vector3 subtract(vector3 a, vector3 b)
{
	return vector3(a.x - b.x, a.y - b.y, a.z - b.z);
}

vector3 scale(double c, vector3 v)
{
	return vector3(c*v.x, c*v.y, c*v.z);
}

vector3 cross(vector3 a, vector3 b)
{
	double x = a.y*b.z - a.z*b.y;
	double y = a.z*b.x - a.x*b.z;
	double z = a.x*b.y - a.y*b.x;
	return vector3(x, y, z);
}

double dot(vector3 a, vector3 b)
{
	return a.x*b.x + a.y*b.y + a.z*b.z;
}

//returns the real number t such that the intersection is t*b1+(1-t)*b2
double intersectPlaneLine(vector3 a1, vector3 a2, vector3 a3, vector3 b1, vector3 b2)
{
	vector3 n = cross(subtract(a2,a1), subtract(a3,a1));
	double d = dot(subtract(b1, b2), n);
	if (abs(d) < 1e-5)
		return -1.0;
	else
		return dot(subtract(a1, b2), n) / dot(subtract(b1, b2), n);
}

double length(vector3 v)
{
	return sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
}

vector3 proj(vector3 v)
{
	return vector3(v.x, v.y, 0);
}

double shoelace(vector<vector3> points)
{
	double sum = 0;
	for (int i = 0; i < points.size() - 1; i++)
		sum += points[i].x * points[i + 1].y;
	for (int i = 0; i < points.size() - 1; i++)
		sum -= points[i].y * points[i + 1].x;
	double ans = abs(sum) / 2;
	return ans;
}

bool inTriangle(vector3 v, triangle t)
{
	double a = shoelace(vector<vector3>{v, t.b, t.c, v});
	double b = shoelace(vector<vector3>{v, t.c, t.a, v});
	double c = shoelace(vector<vector3>{v, t.a, t.b, v});
	double d = shoelace(vector<vector3>{t.a, t.b, t.c, t.a});
	return (a + b + c <= d + 1e-5);
}

//returns the real number t such that the intersection is t*b1+(1-t)*b2
double lineIntersect(vector3 a1, vector3 a2, vector3 b1, vector3 b2)
{
	double A = a2.y - a1.y, B = b1.x - b2.x, C = a2.x - a1.x, D = b1.y - b2.y, E = b2.x - a1.x, F = b2.y - a1.y;
	double X = A*B - C*D, Y = C*F - A*E; //X*t=Y
	if (abs(X) < 1e-5)
		return -1;
	else
		return Y / X;
}

bool isEqual(vector3 a, vector3 b)
{
	return abs(a.x - b.x) < 1e-5 && abs(a.y - b.y) < 1e-5 && abs(a.z - b.z) < 1e-5;
}

double convexHullArea(vector<vector3> points)
{
	if (points.size() < 3)
		return 0.0;
	double smallestx = points[0].x; int index = 0;
	for (int i = 1; i < points.size(); i++)
	{
		if (points[i].x < smallestx)
		{
			smallestx = points[i].x;
			index = i;
		}
	}
	vector<vector3> hull = { points[index] };
	int i = 0; vector3 test;
	do
	{
		test = points[0];
		for (vector3 p : points)
		{
			if (isEqual(p, hull.back()))
				continue;
			double a = test.x - hull[i].x, b = test.y - hull[i].y;
			double c = p.x - hull[i].x, d = p.y - hull[i].y;
			if (a*d - b*c >= -1e-5)
				test = p;
		}
		i++;
		hull.push_back(test);
	} while (!isEqual(hull.front(), hull.back()));

	return shoelace(hull);
}

double intersectionArea(triangle t1, triangle t2)
{
	vector<vector3> convexHull;
	if (inTriangle(t1.a, t2))
		convexHull.push_back(t1.a);
	if (inTriangle(t1.b, t2))
		convexHull.push_back(t1.b);
	if (inTriangle(t1.c, t2))
		convexHull.push_back(t1.c);
	if (inTriangle(t2.a, t1))
		convexHull.push_back(t2.a);
	if (inTriangle(t2.b, t1))
		convexHull.push_back(t2.b);
	if (inTriangle(t2.c, t1))
		convexHull.push_back(t2.c);

	vector<vector3> tri1{ t1.a,t1.b,t1.c }, tri2{ t2.a,t2.b,t2.c };
	for (int i = 0; i < 2; i++)
		for (int j = i+1; j < 3; j++)
			for (int k = 0; k < 2; k++)
				for (int l = k+1; l < 3; l++)
				{
					double t1 = lineIntersect(tri1[i], tri1[j], tri2[k], tri2[l]);
					double t2 = lineIntersect(tri2[k], tri2[l], tri1[i], tri1[j]);
					if (0 < t1 && t1 < 1 && 0 < t2 && t2 < 1)
					{
						/*
						if (inTriangle(tri1[i], t2) && inTriangle(tri1[j], t2))
							continue;
						if (inTriangle(tri2[k], t1) && inTriangle(tri2[l], t1))
							continue;*/
						convexHull.push_back(add(scale(t1, tri2[k]), scale(1 - t1, tri2[l])));
					}
				}

	return convexHullArea(convexHull);
}

double triangleArea(triangle t)
{
	return abs(t.a.x*t.b.y + t.b.x*t.c.y + t.c.x*t.a.y - t.a.y*t.b.x - t.b.y*t.c.x - t.c.y*t.a.x) / 2;
}

double faceSA(vector3 a1, vector3 a2, vector3 a3, vector3 b1, vector3 b2, vector3 b3, vector3 b4)
{
	vector<vector3> intersection;
	double t12 = intersectPlaneLine(a1, a2, a3, b1, b2);
	double t13 = intersectPlaneLine(a1, a2, a3, b1, b3);
	double t14 = intersectPlaneLine(a1, a2, a3, b1, b4);
	double t23 = intersectPlaneLine(a1, a2, a3, b2, b3);
	double t24 = intersectPlaneLine(a1, a2, a3, b2, b4);
	double t34 = intersectPlaneLine(a1, a2, a3, b3, b4);

	if (0 < t12 && t12 < 1)
		intersection.push_back(add(scale(t12, b1), scale(1 - t12, b2)));
	if (0 < t13 && t13 < 1)
		intersection.push_back(add(scale(t13, b1), scale(1 - t13, b3)));
	if (0 < t14 && t14 < 1)
		intersection.push_back(add(scale(t14, b1), scale(1 - t14, b4)));
	if (0 < t34 && t34 < 1)
		intersection.push_back(add(scale(t34, b3), scale(1 - t34, b4)));
	if (0 < t24 && t24 < 1)
		intersection.push_back(add(scale(t24, b2), scale(1 - t24, b4)));
	if (0 < t23 && t23 < 1)
		intersection.push_back(add(scale(t23, b2), scale(1 - t23, b3)));

	vector3 n = cross(subtract(a2, a1), subtract(a3, a1));
	if (n.z == 0)
	{
		if (n.y == 0)
		{
			swap(n.x, n.z);
			swap(a1.x, a1.z);
			swap(a2.x, a2.z);
			swap(a3.x, a3.z);
			swap(b1.x, b1.z);
			swap(b2.x, b2.z);
			swap(b3.x, b3.z);
			swap(b4.x, b4.z);
			for (auto &p : intersection)
				swap(p.x, p.z);
		}
		else
		{
			swap(n.y, n.z);
			swap(a1.y, a1.z);
			swap(a2.y, a2.z);
			swap(a3.y, a3.z);
			swap(b1.y, b1.z);
			swap(b2.y, b2.z);
			swap(b3.y, b3.z);
			swap(b4.y, b4.z);
			for (auto &p : intersection)
				swap(p.y, p.z);
		}
	}
	double sf = length(n) / n.z;
	triangle t = triangle(proj(a1), proj(a2), proj(a3));
	for (int i = 0; i < intersection.size(); ++i)
		intersection[i] = proj(intersection[i]);

	double ans = 0;
	if (intersection.size() == 0)
		ans = abs(triangleArea(t)*sf);
	else if (intersection.size() == 3)
	{
		triangle t2 = triangle(intersection[0], intersection[1], intersection[2]);
		double intArea = intersectionArea(t, t2);
		ans = abs((triangleArea(t) - intArea)*sf);
	}
	else
	{
		triangle t2 = triangle(intersection[0], intersection[1], intersection[2]);
		triangle t3 = triangle(intersection[2], intersection[3], intersection[0]);
		double A2 = intersectionArea(t, t2);
		double A3 = intersectionArea(t, t3);
		ans = abs((triangleArea(t) - A2 - A3)*sf);
	}
	return ans;
}

int main()
{
	vector3 a1, a2, a3, a4, b1, b2, b3, b4;
	scanf("%lf %lf %lf", &a1.x, &a1.y, &a1.z);
	scanf("%lf %lf %lf", &a2.x, &a2.y, &a2.z);
	scanf("%lf %lf %lf", &a3.x, &a3.y, &a3.z);
	scanf("%lf %lf %lf", &a4.x, &a4.y, &a4.z);
	scanf("%lf %lf %lf", &b1.x, &b1.y, &b1.z);
	scanf("%lf %lf %lf", &b2.x, &b2.y, &b2.z);
	scanf("%lf %lf %lf", &b3.x, &b3.y, &b3.z);
	scanf("%lf %lf %lf", &b4.x, &b4.y, &b4.z);

	double ans = 0.0;
	double a, b, c, d, e, f, g, h;
	a = faceSA(a1, a2, a3, b1, b2, b3, b4);
	b = faceSA(a1, a2, a4, b1, b2, b3, b4);
	c = faceSA(a1, a3, a4, b1, b2, b3, b4);
	d = faceSA(a2, a3, a4, b1, b2, b3, b4);
	e = faceSA(b1, b2, b3, a1, a2, a3, a4);
	f = faceSA(b1, b2, b4, a1, a2, a3, a4);
	g = faceSA(b1, b3, b4, a1, a2, a3, a4);
	h = faceSA(b2, b3, b4, a1, a2, a3, a4);
	
	printf("%f", a+b+c+d+e+f+g+h);
    return 0;
}