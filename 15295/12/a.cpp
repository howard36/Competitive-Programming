#include <bits/stdc++.h>
using namespace std;


int f[30];

int main() {
	string s;
	cin >> s;
	int n = s.length();
	for (int i = 0; i<n; i++) {
		f[s[i]-'a']++;
	}
	int cnt = 0;
	for (int i = 0; i<26; i++) {
		if (f[i] %2 == 1)
			cnt++;
	}
	if (cnt < 2 || n % 2 == 1)
		cout << "First" << endl;
	else 
		cout << "Second" << endl;
}
