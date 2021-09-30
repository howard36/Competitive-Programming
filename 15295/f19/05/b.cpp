#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int, int>

vector<string> ans;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i<n; i++) {
		string s;
		cin >> s;
		if (s.length() < 6)
			continue;
		bool a = false, b = false, c = false, d = false;
		for (int j = 0; j<s.length(); j++) {
			int x = s[j]-'a';
			if (x >= 0 && x < 26)
				a = true;
			x = s[j]-'A';
			if (x >= 0 && x < 26)
				b = true;
			x = s[j]-'0';
			if (x >= 0 && x < 10)
				c = true;
			if (s[j] == '.' || s[j] == ',' || s[j] == ':' || s[j]==';'||s[j]=='?'||s[j]== '!')
				d = true;
		}
		if (a && b && c && d)
			ans.push_back(s);
	}
	printf("%d\n", (int)ans.size());
	for (string s : ans) 
		cout << s << endl;
}
