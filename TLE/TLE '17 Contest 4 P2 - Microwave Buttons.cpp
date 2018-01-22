#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> convert(int i) {
	vector<int> v(6);
	for (int j = 5; j >= 0; --j) {
		v[j] = i % 10;
		i /= 10;
	}
	return v;
}

int main()
{
	string T, buttons;
	cin >> T >> buttons;
	int time = (10 * (T[0] - '0') + (T[1] - '0')) * 3600 + (10 * (T[3] - '0') + (T[4] - '0')) * 60 + (10 * (T[6] - '0') + (T[7] - '0'));
	int minimum = 1000000000;
	vector<int> V(6);
	for (int i = 0; i < 1000000; ++i) {
		vector<int> v = convert(i);
		bool stop = false;
		for (int j = 0; j < 6; ++j) {
			if (buttons.find((char)(v[j] + '0')) == string::npos)
				stop = true;
		}
		if (stop)
		    continue;
		int time2 = (10 * v[0] + v[1]) * 3600 + (10 * v[2] + v[3]) * 60 + (10 * v[4] + v[5]);
		if (abs(time2 - time) < minimum) {
			minimum = abs(time2 - time);
			for (int j = 0; j < 6; ++j)
			    V[j] = v[j];
		}
	}
	printf("%d%d:%d%d:%d%d", V[0], V[1], V[2], V[3], V[4], V[5]);
    return 0;
}