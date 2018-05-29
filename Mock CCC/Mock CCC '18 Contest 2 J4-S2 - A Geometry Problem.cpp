#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int a1, a2, a3, b1, b2, b3;
	scanf("%d%d%d%d%d%d", &a1, &b1, &a2, &b2, &a3, &b3);
	if (a1 > b1)
		swap(a1, b1);
	if (a2 > b2)
		swap(a2, b2);
	if (a3 > b3)
		swap(a3, b3);
	if (b1 == b2 && b2 == b3 && a1 + a2 + a3 == b1)
		printf("YES");
	else {
		if (b1 < b2) {
			swap(a1, a2);
			swap(b1, b2);
		}
		if (b2 < b3) {
			swap(a3, a2);
			swap(b3, b2);
		}
		if (b1 < b2) {
			swap(a1, a2);
			swap(b1, b2);
		}
		int h = b1 - a1;
		if (a2 == h || b2 == h) {
			if (b2 == h)
				swap(a2, b2);
			if (a3 == h || b3 == h) {
				if (b3 == h)
					swap(a3, b3);
				if (b2 + b3 == b1)
					printf("YES");
				else
					printf("NO");
			}
			else
				printf("NO");
		}
		else
			printf("NO");
	}
    return 0;
}