#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int mutations(string s1, string s2) {
	int count = 0;
	for (int i = 0; i < s1.length(); i++) {
		if (s1[i] != s2[i])
			count++;
	}
	return count;
}

int diff[10004][2];

int main()
{
	for (int iii = 0; iii < 10; iii++) {
		string p1, p2, c;
		cin >> p1 >> p2 >> c;
		int least = 1000000;
		for (int i = 0; i < p1.length(); i++) {
			if (i == 0) {
				diff[i][0] = 0;
				diff[i][1] = 0;
			}
			else {
				diff[i][0] = diff[i - 1][0];
				diff[i][1] = diff[i - 1][1];
			}
			if (p1[i] != c[i])
				diff[i][0]++;
			if (p2[i] != c[i])
				diff[i][1]++;
		}
		for (int i = 1; i < p1.length(); i++) {
			for (int j = i + 1; j < p1.length() - 1; j++) {
				int test1 = diff[i - 1][0] + (diff[j - 1][1] - diff[i - 1][1]) + (diff[p1.length() - 1][0] - diff[j - 1][0]);
				int test2 = diff[i - 1][1] + (diff[j - 1][0] - diff[i - 1][0]) + (diff[p1.length() - 1][1] - diff[j - 1][1]);
				least = min(least, test1);
				least = min(least, test2);
			}
		}
		printf("%.2lf\n", (double)least / p1.length());
	}
    return 0;
}