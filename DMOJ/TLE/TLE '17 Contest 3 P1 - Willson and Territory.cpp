#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int x, y, x0, y0, N, m = 0;
	scanf("%d%d%d", &x0, &y0, &N);
	while (N--)
	{
		scanf("%d%d", &x, &y);
		m = max(m, abs(x - x0) + abs(y - y0));
	}
	printf("%d", 2 * m*m);
    return 0;
}