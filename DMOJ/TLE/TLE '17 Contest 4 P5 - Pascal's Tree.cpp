#include <cstdio>
#define ll long long
using namespace std;

int choose[9003][9003];
ll row[100005];

int main()
{
	int N = 8000, M = 1000, x, y;
	scanf("%d %d", &x, &y);
	choose[0][0] = 1;
	for (int n = 1; n <= N; ++n) {
		choose[n][0] = 1;
		for (int k = 1; k <= n; ++k) {
			choose[n][k] = (choose[n - 1][k - 1] + choose[n - 1][k]) % M;
		}
	}
    return 0;
}