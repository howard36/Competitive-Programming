#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	int K, P, X;
	scanf("%d%d%d", &K, &P, &X);
	int M1 = sqrt(K * P / X);
	int M2 = M1 + 1;
	printf("%.3f", min(M1*X + 1.0*K*P / M1, M2*X + 1.0*K*P / M2));
    return 0;
}