#include <bits/stdc++.h>
using namespace std;

vector<string> strings;

void reverse(string &s, int a, int b) {
    for (int i = a; i<(a+b)/2; i++){
        swap(s[i], s[b-(i-a)-1]);
    }
}

int main() {
	string s;
	cin >> s;
	int n = s.length();
	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			string copy = s;
			reverse(copy, 0, i);
			reverse(copy, i, j);
			reverse(copy, j, n);
            strings.push_back(copy);
		}
	}
    sort(strings.begin(), strings.end());
    cout << strings[0];
}