#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, s, i, e;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d %d", &s, &i, &e);
		printf("%d\n", min(e+1, max(0, (s+e-i+1)/2)));
	}
}
