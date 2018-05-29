#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
using namespace std;

int a[10];
int test[10];
set<int> good;
int freq[10];
int state[10];

bool check() {
	memset(freq, 0, sizeof freq);
	for (int i : state)
		freq[i]++;
	if (freq[1] != 2 || freq[2] != 2 || freq[3] != 2 || freq[4] != 1 || freq[5] != 1)
		return false;
	int bishop[2] = { 0,0 };
	for (int i = 1; i <= 8; i++) {
		if (state[i] == 3)
			bishop[i % 2]++;
	}
	if (bishop[0] != 1)
		return false;
	int k, r1, r2;
	for (int i = 1; i <= 8; i++) {
		if (state[i] == 4)
			k = i;
		if (state[i] == 1)
			r2 = i;
	}
	for (int i = 8; i >= 1; i--) {
		if (state[i] == 1)
			r1 = i;
	}
	if (r1 < k && k < r2)
		return true;
	return false;
}

int convert() {
	int ret = 0;
	for (int i = 1; i <= 8; i++) {
		ret *= 10;
		ret += state[i];
	}
	return ret;
}

int main()
{
	for (int abc = 0; abc < 10; abc++) {
//		string S;
//		cin >> S;
		for (int i = 1; i <= 8; i++) {
//			char c = S[i-1];
			char c;
			scanf(" %c", &c);
			if (c == 'R')
				a[i] = 1;
			else if (c == 'N')
				a[i] = 2;
			else if (c == 'B')
				a[i] = 3;
			else if (c == 'K')
				a[i] = 4;
			else if (c == 'Q')
				a[i] = 5;
			else
				a[i] = 0;
		}
		good.clear();
		for (int i = 0; i <= 8; i++) {
			test[i] = i;
		}
		do {
			for (int i = 0; i <= 8; i++) {
				if (test[i] < 6)
					state[i] = test[i];
				else
					state[i] = 9 - test[i];
			}
			bool match = true;
			for (int i = 0; i <= 8; i++) {
				if (state[i] != a[i] && a[i] != 0) {
					match = false;
				}
			}
			if (match) {
				if (check()) {
					good.insert(convert());
				}
			}
		} while (next_permutation(test+1, test + 9));
		printf("%d\n", good.size());
	}
    return 0;
}