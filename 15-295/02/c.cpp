#include <bits/stdc++.h>
using namespace std;

int n, k;
double l, v1, v2;

int main() {
	scanf("%d %lf %lf %lf %d", &n, &l, &v1, &v2, &k);
	int K = (n+k-1)/k;
	double c = K/(v2-v1) + (K-1)/(v2+v1);
	printf("%.7lf\n", l*c/(1+c*v1));
}
