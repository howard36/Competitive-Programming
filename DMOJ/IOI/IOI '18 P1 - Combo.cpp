#include <bits/stdc++.h>
using namespace std;

string guess_sequence(int N) {
	char c[3];
	string S = "";
	if (press("AB") > 0) {
		c[0] = 'X', c[1] = 'Y';
		if (press("A") == 1) {
			S = "A";
			c[2] = 'B';
		}
		else {
			S = "B";
			c[2] = 'A';
		}
	}
	else {
		c[0] = 'A', c[1] = 'B';
		if (press("X") == 1) {
			S = "X";
			c[2] = 'Y';
		}
		else {
			S = "Y";
			c[2] = 'X';
		}
	}
    if (N == 1){
        return S;
    }
	for (int i = 1; i < N - 1; i++) {
		int r = press(S + c[0] + S + c[1] + c[0] + S + c[1] + c[1] + S + c[1] + c[2]);
		if (r == i) {
			S += c[2];
		}
		else if (r == i + 1) {
			S += c[0];
		}
		else {
			S += c[1];
		}
	}
	if (press(S + c[0]) == N) {
		S += c[0];
	}
	else if (press(S + c[1]) == N) {
		S += c[1];
	}
	else {
		S += c[2];
	}
	return S;
}