#include <cstdio>
#include <cmath>
int main()
{
	double a = 0.0, b = 0.0;
	int N, x;
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) {
		scanf("%d", &x);
		if (x)
			++b;
		else
			++a;
		printf("%f\n", (sqrt(a*b)-b)/(a-b));
	}
    return 0;
}