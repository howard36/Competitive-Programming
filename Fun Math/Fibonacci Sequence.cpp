#include <iostream>
#include <vector>
#define mod 1000000007
using namespace std;
using matrix = vector<long long>;

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

int main()
{
	unsigned long long n;
	cin >> n;
	matrix X{ 1,1,1,0 };
	cout << fastExp(X, n)[1];
    return 0;
}