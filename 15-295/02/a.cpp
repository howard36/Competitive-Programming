#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n1, n2, n3, p1, p2, p3;
ll r;
ll f1 = 0, f2 = 0, f3 = 0;

bool can(ll k) {
	return (p1*max(k*f1-n1, 0LL) + p2*max(k*f2-n2, 0LL) + p3*max(k*f3-n3, 0LL) <= r);
}


int main() {
	string s;
	cin >> s;
	cin >> n1 >> n2 >> n3 >> p1 >> p2 >> p3;
	cin >> r;
	for (int i = 0; i<s.size(); i++) {
		if (s[i] == 'B')
			f1++;
		else if (s[i] == 'S')
			f2++;
		else
			f3++;
	}
	
	ll lo = 0, hi = 1e13;
	while (lo < hi) {
		ll mid = (lo + hi + 1)/2;
		if (can(mid))
			lo = mid;
		else
			hi = mid - 1;
	}
	cout << lo << endl;
}
