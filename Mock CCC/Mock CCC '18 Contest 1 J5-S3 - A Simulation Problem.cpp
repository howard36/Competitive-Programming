#include <cstdio>
#include <cmath>

int f2(int N) {
	double T = 1.0*N*(N - 1) / 2;
	double B = 2.0*N - 1;
	double ans = (B - sqrt(B*B - 4 * T)) / 2;
	return ceil(ans);
}

int main()
{
	int N;
	scanf("%d", &N);
	printf("%d", f2(N));
}