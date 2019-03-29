#include <bits/stdc++.h>

int main() {
	int n;
	scanf("%d", &n);
	char c;
	bool DNA = true, RNA = true;
	for (int i = 0; i < n; i++) {
		scanf(" %c", &c);
		if (c != 'A' && c != 'C' && c != 'G' && c != 'T') {
			DNA = false;
		}
		if (c != 'A' && c != 'C' && c != 'G' && c != 'U') {
			RNA = false;
		}
	}
    if (DNA && RNA){
        printf("both");
    }
    else if (DNA) {
        printf("DNA");
    }
    else if (RNA){
        printf("RNA");
    }
    else {
        printf("neither");
    }
}