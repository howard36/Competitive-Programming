#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int, int>

stack<int> st;
int a[1000006];

int main() {
	string s;
	cin >> s;
	int n = s.length();
	for (int i = n-1; i>=0; i--) {
		while (!st.empty() && s[st.top()] > s[i]) {
			a[st.top()] = 1;
			st.pop();
		}
		st.push(i);
	}
	for (int i = 0; i<n; i++) {
		if (a[i])
			printf("Ann\n");
		else
			printf("Mike\n");
	}
}
