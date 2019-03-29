#include <bits/stdc++.h>
using namespace std;

int main() {
	int w;
	scanf("%d", &w);
	for (int l = 1, poww = 26; w > 0; poww *= 26, l++) {
		for (int i = 0; i < poww && w > 0; i++, w--) {
			for (int ii = i, j = 0; j < l; j++, ii /= 26) {
                printf("%c", 'a'+ii%26);
			}
            printf(" ");
		}
	}
}