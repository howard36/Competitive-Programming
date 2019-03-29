#include <bits/stdc++.h>
using namespace std;

int minimum[1003], maximum[1003];

int main() {
	int r, s;
	char c;
	scanf("%d %d", &r, &s);
    int highest = 0;
	for (int i = r - 1; i >= 0; i--) {
		minimum[i] = s - 1;
        bool hasApple = false;
		for (int j = 0; j < s; j++) {
			scanf(" %c", &c);
			if (c == 'J') {
				minimum[i] = min(minimum[i], j);
				maximum[i] = max(maximum[i], j);
                hasApple = true;
			}
		}
        if (hasApple){
            highest = max(highest, i);
        }
	}
    minimum[r] = s-1;
	int pos = 0, ans = 0;
	for (int i = 0; i <= highest; i++) {
		if (i % 2 == 0) {
            int go = max(maximum[i], maximum[i+1]);
			if (pos < go) {
				ans += go - pos;
				pos = go;
			}
		}
		else {
            int go = min(minimum[i], minimum[i+1]);
			if (pos > go) {
				ans += pos - go;
				pos = go;
			}
		}
		ans++;
	}
    printf("%d", ans-1);
}