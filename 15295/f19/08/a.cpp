#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define cd complex<ld>


int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i<n; i++) {
		int a;
		scanf("%d", &a);
		if (360 % (180-a) == 0)
			printf("YES\n");
		else
			printf("NO\n");
	}

}
