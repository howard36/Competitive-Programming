#include <bits/stdc++.h>
using namespace std;

string a[4], b[4], sa[4], sb[4];

int main() {
	for (int i = 0; i < 4; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> b[i];
	}
	for (int i = 0; i < 4; i++) {
		for (int j = i + 1; j < 4; j++) {
			if (a[i] == a[j] || b[i] == b[j]) {
				printf("NO");
				return 0;
			}
		}
	}
	for (int i = 0; i < 4; i++) {
		sa[i] = a[i];
		sb[i] = b[i];
	}
	sort(sa, sa + 4);
	sort(sb, sb + 4);
    for (int i = 0; i<4; i++){
        if (sa[i] != sb[i]){
            printf("NO");
            return 0;
        }
    }
    int cnt = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = i + 1; j < 4; j++) {
			if (a[i] > a[j]) {
                cnt ^= 1;
			}
            if (b[i] > b[j]){
                cnt ^= 1;
            }
		}
	}
    if (cnt == 1){
        printf("YES");
    }
    else {
        printf("NO");
    }
}