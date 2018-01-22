#include <iostream>
using namespace std;
int main()
{
	int n, x;
	long long dmax = 0, dmin = 0, max, min;
	bool hasOdd = false;
	cin >> n;
	while (n--)
	{
		cin >> x;
		if (x % 2 != 0)
			hasOdd = true;
		dmax += 2 * x + 1;
		dmin += 2 * x - 1;
	}

	if (dmax % 2 == 0 || hasOdd)
		max = dmax / 2;
	else
	{
		if ((dmax / 2) % 2 == 0)
			max = dmax / 2;
		else
			max = dmax / 2 + 1;
	}

	if (dmin % 2 == 0)
		min = dmin / 2;
	else
	{
		if (hasOdd || (dmin / 2) % 2 != 0)
			min = dmin / 2 + 1;
		else
			min = dmin / 2;
	}
	cout << min << '\n' << max;
    return 0;
}