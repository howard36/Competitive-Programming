#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int, int>

int main() {
	int n, o = 0, z = 0;
	scanf("%d", &n);
	for (int i = 0; i<n; i++) {
		char c;
		scanf(" %c", &c);
		if (c == 'n')
			o++;
		else if (c == 'z')
			z++;
	}
	for (int i = 0; i<o; i++)
		printf("1 ");
	for (int i = 0; i<z; i++)
		printf("0 ");
}
