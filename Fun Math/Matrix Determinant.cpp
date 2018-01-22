//Converts matrix into an upper triangular matrix using Gaussian elimination.
//The determinant is the product of all the diagonal entries.
//Each time makeRowZero is called, the determinant is multiplied by x, so we must divide by scale at the end.

#include <utility>
#include <stdio.h>
#define gcu getchar_unlocked
#define scan(x) do{while((x=gcu())<'-');if(x-45)_neg=false;else{_neg=true;x=gcu();}for(x-='0';'0'<=(_=gcu());x=(x<<3)+(x<<1)+_-'0');if(_neg)x=-x;}while(0)
char _; bool _neg;
#define ll long long
#define mod 1000000007LL

using namespace std;

ll M[500][500];
int N;
ll scale = 1;
ll det = 1;

inline ll inverse(ll a, ll b)
{
	int pre = 0, cur = 1;
	ll r[2] = { a,b }, s[2] = { 1,0 }, t[2] = { 0,1 };
	ll q;

	while (r[cur] != 0)
	{
		pre ^= 1; cur ^= 1;
		q = r[cur] / r[pre];
		r[cur] = r[cur] - q*r[pre];
		s[cur] = s[cur] - q*s[pre];
		t[cur] = t[cur] - q*t[pre];
	}
	return s[pre]%mod;
}

inline bool swapWithNonZeroRow(int i)
{
	for (int j = i + 1; j < N; j++)
	{
		if (M[j][i] != 0)
		{
			swap(M[i], M[j]);
			det *= -1;
			return true;
		}
	}
	return false;
}

inline void makeRowZero(int i, int j)
{
	ll x = M[i][i];
	ll y = M[j][i];
	for (int k = i; k < N; k++)
	{
		M[j][k] = (x*M[j][k] - y*M[i][k]) % mod;
	}
	scale *= x;
	scale %= mod;
}

int main()
{
	scan(N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scan(M[i][j]);

	for (int i = 0; i < N; i++)
	{
		if (M[i][i] == 0)
		{
			if (!swapWithNonZeroRow(i))
			{
				det = 0;
				break;
			}
		}
		for (int j = i + 1; j < N; j++)
		{
			makeRowZero(i, j);
		}
		det *= M[i][i];
		det %= mod;
	}
	if (det != 0)
	{
		if (scale < 0)
			scale += mod;
		ll inv = inverse(scale, mod);
		det *= inv;
		det %= mod;
	}
	if (det < 0)
		det += mod;
	printf("%lld", det);
	return 0;
}