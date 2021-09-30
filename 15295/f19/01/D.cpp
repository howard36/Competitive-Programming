#include <bits/stdc++.h>
using namespace std;

int freq[1024], temp[1024];

int main() {
	int n, k, x;
	scanf("%d %d %d", &n, &k, &x);
	for (int i = 0; i < n; i++) {
		int y;
        scanf("%d", &y);
        freq[y]++;
	}
    for (int i = 0; i<k; i++){
        int carry = 0;
        for (int j = 0; j<1024; j++) {
            int move = (freq[j] + 1 - carry)/2;
            carry = (carry + freq[j]) % 2;
            freq[j] -= move;
            temp[j^x] = move;
        }
        for (int j = 0; j<1024; j++)
            freq[j] += temp[j];
    }
    int M = -1, m = 1024;
    for (int i = 0; i<1024; i++) {
        if (freq[i])
            M = i;
	}
	for (int i = 1023; i >= 0; i--) {
		if (freq[i])
			m = i;
	}
    printf("%d %d", M, m);
}