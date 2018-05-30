#include "stdafx.h"

#define ll long long

ll fastPow(ll b, int exp) {
	ll ans = 1, pow = b;
	while (exp > 0)
	{
		if (exp & 1)
			ans *= pow;
		exp >>= 1;
		pow = pow * pow;
	}
	return ans;
}