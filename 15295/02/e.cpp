#include <bits/stdc++.h>
using namespace std;
#define cd complex<double>
 
double reach(cd S, cd V, double v) {
	double a = v*v - abs(V)*abs(V);
	double b = -(2*real(V)*real(S) + 2*imag(V)*imag(S));
	double c = -abs(S)*abs(S);
	return (-b + sqrt(b*b-4*a*c))/(2*a);
}
 
int main() {
	int x1, x2, y1, y2;
	double v, t, vx, vy, wx, wy;
	scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
	scanf("%lf %lf %lf %lf %lf %lf", &v, &t, &vx, &vy, &wx, &wy);
	cd S = cd(x2-x1, y2-y1);
	cd V = cd(-vx, -vy), W = cd(-wx, -wy);
	cd T = S + t*V - t*W;
	double reach_time = reach(S, V, v);
	if (reach_time < t)
		printf("%.10lf\n", reach_time);
	else
		printf("%.10lf\n", reach(T, W, v));
}
