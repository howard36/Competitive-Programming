#include <bits/stdc++.h>

int r, c;

bool row(int i) {
	return i == 0 || i == (r - 1);
}

bool col(int j) {
	return j == 0 || j == (c - 1);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &r, &c);
        bool good = true;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				int a;
				scanf("%d", &a);
				if (row(i) && col(j)){
                    if (a >= 2) {
                        good = false;
                    }
                }
                else if (row(i) || col(j)){
                    if (a >= 3)
                        good = false;
                }
                else {
                    if (a >= 4)
                        good = false;
                }
			}
		}
        if (good){
            printf("Stable\n");
        }
        else {
            printf("Unstable\n");
        }
	}
}