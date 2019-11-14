#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		if (k % 3 != 0) {
			if (n % 3 == 0)
				cout << "Bob" << endl;
			else
				cout << "Alice" << endl;
		}
		else {
			n %= k+1;
			if (n % 3 == 0 && n != k) 
				cout << "Bob" << endl;
			else
				cout << "Alice" << endl;
		}
	}

}
