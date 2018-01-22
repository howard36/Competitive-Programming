#include <cstdio>
#define ll long long

int L[19], R[19];

int main()
{
	ll l, r;
	scanf("%lld %lld", &l, &r);
	if (l == r)
	{
		printf("1");
		return 0;
	}
	for (int i = 0; i < 19; ++i)
	{
		L[i] = l % 10;
		R[i] = r % 10;
		l /= 10;
		r /= 10;
	}
	int determined = 18, sum = 0;
	while (L[determined] == R[determined])
	{
		sum += L[determined];
		--determined;
	}
	bool allzero = true, allnine = true;
	for (int digit = determined - 1; digit >= 0; --digit) {
		if (L[digit] != 0)
			allzero = false;
		if (R[digit] != 9)
			allnine = false;
	}
	ll min = sum + L[determined] + 1;
	if (allzero)
		--min;
	ll max = sum + R[determined] - 1 + 9 * determined;
	if (allnine)
		++max;
	printf("%lld", max - min + 1);
    return 0;
}