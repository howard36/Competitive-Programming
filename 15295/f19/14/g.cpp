#include <bits/stdc++.h>
using namespace std;

int a[102];

int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i<k-1; i++) 
		a[i] = i;
	for (int i = k-1; i<n; i++) {
		string s;
		cin >> s;
		if (s == "NO")
			a[i] = a[i-k+1];
		else
			a[i] = i;
	}
	for (int i = 0; i<n; i++) {
		if (a[i] < 26)
			cout << 'A';
		else
			cout << 'B';
		cout << (char)('a' + a[i]%26) << ' ';
	}
}
