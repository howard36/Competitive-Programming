#include <cstdio>
using namespace std;

int main()
{
	long long n, k;
	scanf("%lld%lld", &n, &k);
	if (k*k < n)
		printf("-1");
	else
	{
		for (int i = 0; i <= n / k; i++)
			for (int j = k; j > 0; j--)
			{
				int num = i*k + j;
				if (num <= n)
					printf("%d ", num);
			}
	}
	return 0;
}