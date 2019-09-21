#include <bits/stdc++.h>
using namespace std;
#define ll long long

string A = "Good writing is good ",
	   B = " writing is good ",
	   C = " is good writing.",
	   f0 = "Good writing is good writing is good writing.";
ll a = A.length(), b = B.length(), c = C.length();

ll l[50];

char f(int n, ll k) {
	if (k >= l[n])
		return '.';
	if (n == 0)
		return f0[k];
	if (k < a)
		return A[k];
	k -= a;
	if (k < l[n-1])
		return f(n-1, k);
	k -= l[n-1];
	if (k < +b)
		return B[k];
	k -= b;
	if (k < l[n-1])
		return f(n-1, k);
	k -= l[n-1];
	return C[k];
}

int main() {
	int q, n;
	ll k;
	l[0] = f0.length();
	for (int i = 1; i<40; i++) {
		l[i] = a+b+c+2*l[i-1];
	}
	scanf("%d", &q);
	while (q--) {
		scanf("%d %lld", &n, &k);
		printf("%c\n", f(n, k-1));
	}
}
