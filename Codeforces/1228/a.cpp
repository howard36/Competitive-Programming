#include <bits/stdc++.h>
using namespace std;

int a[10];

int main() {
	int l, r;
	scanf("%d %d", &l, &r);
	for (int i = l; i <= r; i++) {
		int j = 0, ii = i;
		while (ii) {
			a[j] = ii%10;
			ii /= 10;
			j++;
		}
		sort(a, a+j);
		bool works = true;
		for (int jj = 0; jj<j-1; jj++)
			if (a[jj] == a[jj+1])
				works = false;
		if (works) {
			printf("%d\n", i);
			return 0;
		}
	}
	printf("-1");
}
