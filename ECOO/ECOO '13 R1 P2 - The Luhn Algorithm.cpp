#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;


int digitsum(int n) {
	int sum = 0;
	while (n) {
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

int main()
{
	int x = 0;
	for (int line = 0; line < 5; line++) {
		for (int num = 0; num < 5; num++) {
			string S;
			cin >> S;
			int n = S.length();
			int sum = 0;
			for (int i = n - 1; i >= 0; i -= 2) {
				sum += digitsum(2*(S[i] - '0'));
			}
			for (int i = n - 2; i >= 0; i -= 2) {
				sum += S[i] - '0';
			}
			sum %= 10;
			sum = 10 - sum;
			sum %= 10;
			printf("%d", sum);
		}
		printf("\n");
	}
    return 0;
}