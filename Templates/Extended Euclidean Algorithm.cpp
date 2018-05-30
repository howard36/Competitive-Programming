#include <bits/stdc++.h>
using namespace std;

//Given 2 positive integers a and b, it returns the pair (s,t) such that as+bt=gcd(a,b).
//Also, r[pre]=gcd(a,b), s[cur]= +/- b/gcd(a,b), and t[cur]= +/- a/gcd(a,b) at the end.
//https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm

pair<int, int> ExtendedEuclideanAlgorithm(int a, int b) {
	int pre = 0, cur = 1;
	int r[2] = { a,b }, s[2] = { 1,0 }, t[2] = { 0,1 };
	int q;

	while (r[cur] != 0)	{
		q = r[pre] / r[cur];
		r[pre] -= q*r[cur];
		s[pre] -= q*s[cur];
		t[pre] -= q*t[cur];
		pre ^= 1; cur ^= 1;
	}
	return make_pair(s[pre], t[pre]);
}
