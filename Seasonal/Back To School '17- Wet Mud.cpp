#include <iostream>
using namespace std;
int times[300000];
int m, n, j, p, t;
int pos = 0, timePassed = 0;
int main()
{
	for (int i = 0; i < 300000; i++)
		times[i] = 1234567;
	cin >> n >> m >> j;
	for (int i = 0; i < m; i++)
	{
		cin >> p >> t;
		times[p] = t;
	}
	times[n+1] = 0;

	while (pos < n+1 && timePassed < 1234567)
	{
		int minTime = 1234567, posMinTime;
		bool instantJump = false;
		for (int i = pos + j; i > pos; i--)
		{
			if (times[i] < timePassed) //already dry
			{
				pos = i;
				instantJump = true;
				break;
			}
			if (times[i] < minTime)
			{
				minTime = times[i];
				posMinTime = i;
			}
		}
		if (instantJump)
			continue;
		if (minTime == 1234567) //nowhere to jump to
			timePassed = 1234567;
		else
		{
			timePassed = minTime;
			pos = posMinTime;
		}
	}
	if (pos == n + 1)
		cout << timePassed;
	else
		cout << -1;
    return 0;
}