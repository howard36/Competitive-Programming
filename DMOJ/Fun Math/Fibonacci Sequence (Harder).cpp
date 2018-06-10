#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007LL // period is 2p+2
#define ll long long
using matrix = vector<ll>;

char s[100005];
vector<int> N;
int d;


matrix multiply(matrix A, matrix B)
{
	matrix C;
	C.push_back((A[0] * B[0] + A[1] * B[2]) % mod);
	C.push_back((A[0] * B[1] + A[1] * B[3]) % mod);
	C.push_back((A[2] * B[0] + A[3] * B[2]) % mod);
	C.push_back((A[2] * B[1] + A[3] * B[3]) % mod);
	return C;
}

matrix fastExp(matrix base, unsigned long long exp)
{
	matrix mult = base;
	matrix ans{ 1,0,0,1 };
	if (exp == 0)
		return ans;
	while (exp > 0)
	{
		if (exp % 2 == 1)
			ans = multiply(ans, mult);
		mult = multiply(mult, mult);
		exp /= 2;
	}
	return ans;
}

int main() {
    scanf("%s", s);
    d = strlen(s);
    for (int i = d-1; i>=0; i--){
        N.push_back(s[i]-'0');
    }
    while (d >= 18) {
        ll start = 0;
        for (int i = d-1; i >= d-18; i--) {
            start = 10*start+N[i];
        }
        start %= (2*mod+2); // 2*mod+2 is the period
        for (int i = d-18; i < d; i++, start /= 10){
            N[i] = start % 10;
        }
        while (N.size() && N[d-1] == 0){
            N.pop_back();
            d--;
        }
    }
    ll n = 0;
    for (int i = d-1; i >= 0; i--) {
        n = 10*n+N[i];
    }
    matrix base = {1, 1, 1, 0};
    printf("%lld\n", fastExp(base, n)[1]);
}
