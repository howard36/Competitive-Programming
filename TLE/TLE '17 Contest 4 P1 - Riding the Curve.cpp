#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
	int m, n, k;
	scanf("%d%d%d", &m, &k, &n);
	double x = 0.595*n - k;
	int required = ceil(x);
	if (required > m)
		printf("have mercy snew");
	else
		printf("%d", max(required, 0));
	return 0;
}