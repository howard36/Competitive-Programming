#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll a[100005];

int main() {
	int n;
	cin >> n;
	ll sum = 0;
	for (int i = 0; i<n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	sort(a, a+n);
	int bad = 0;
	for (int i = 0; i<n-1; i++) {
		if (a[i] == a[i+1]) {
			bad++;
			if (a[i] == 0)
				bad = 2;
			if (i > 0 && (a[i-1] == a[i] || a[i-1] == a[i] - 1))
				bad = 2;
		}
	}
	
	if (bad > 1 || sum == 0 || (sum + n*(n-1)/2) % 2 == 0) {
		cout << "cslnb" << endl;
	}
	else
		cout << "sjfnb" << endl;
}
