#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int N, a, left = 0, right = 0;;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a);
		if (a <= 500000)
			left = a - 1;
		else {
			right = 1000000 - a;
			break;
		}
	}
	printf("%d", max(left, right));
    return 0;
}
