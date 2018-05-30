#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

int main()
{
	int N; string S, name;
	getline(cin, S);
	stringstream temp1(S);
	temp1 >> N;
	getline(cin, name);
	while (N--) {
		getline(cin, S);
		int l = S.length();
		int slash = -1, space = -1;
		for (int i = 0; i < l; i++) {
			if (S[i] == '/')
				slash = i;
			if (S[i] == ' ')
				space = i;
		}
		if (slash == -1) {
			cout << "Y\n";
			continue;
		}
		int x;
		stringstream temp2(S.substr(0, slash));
		temp2 >> x;
		if (space == -1) {
			int n;
			stringstream temp3(S.substr(slash + 1, l - slash - 1));
			temp3 >> n;
			if (x > n)
				cout << "Y\n";
			else
				cout << "N\n";
			continue;
		}
		int n;
		stringstream temp4(S.substr(slash + 1, space - slash - 1));
		temp4 >> n;
		if (x <= n) {
			cout << "N\n";
			continue;
		}
		/*
		bool match = true;
		for (int i = 0; i + space + 1 < l; i++) {
			if (i >= name.length() || name[i] != S[i + space + 1]) {
				match = false;
				break;
			}
		}
		if (match)
			cout << "Y\n";
		else
			cout << "N\n";
			*/
		string name2 = S.substr(space + 1, l - space - 1);
		if (mismatch(name2.begin(), name2.end(), name.begin()).first == name2.end())
			cout << "Y\n";
		else
			cout << "N\n";

	}
    return 0;
}