#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int digits[10];
vector<int> tests;

int main()
{
	int N, M;
	scanf("%d%d", &N, &M);
	int mid = (N + M) / 2;
	int midcopy = mid;
	int d = 0;
	while (midcopy > 0) {
		digits[d] = midcopy % 10;
		midcopy /= 10;
		d++;
	}
	for (int i = 0; i < d / 2; i++) {
		digits[i] = digits[d - i - 1];
	}
	int test1 = 0;
	for (int i = d-1; i >= 0; i--) {
		test1 *= 10;
		test1 += digits[i];
	}
	int change;
	if (test1 < mid) {
		if (digits[d / 2] == 9) {
			digits[d / 2] = 0;
			digits[(d - 1) / 2] = 0;
			digits[d / 2 + 1]++;
			digits[(d - 1) / 2 - 1]++;
		}
		else {
			digits[d / 2]++;
			if (d % 2 == 0) {
				digits[d / 2 - 1]++;
			}
		}
	}
	else {
		if (digits[d / 2] == 0) {
			digits[d / 2] = 9;
			digits[(d - 1) / 2] = 9;
			digits[d / 2 + 1]--;
			digits[(d - 1) / 2 - 1]--;
		}
		else {
			digits[d / 2]--;
			if (d % 2 == 0) {
				digits[d / 2 - 1]--;
			}
		}
	}
	int test2 = 0;
	for (int i = d - 1; i >= 0; i--) {
		test2 *= 10;
		test2 += digits[i];
	}
	int diff1 = min(abs(N - test1), abs(M - test1));
	int diff2 = min(abs(N - test2), abs(M - test2));
	if (diff1 > diff2) {
		printf("%d", test1);
	}
	else {
		printf("%d", test2);
	}
    return 0;
}