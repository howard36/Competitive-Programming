#include <iostream>

#define ll long long
#define MOD 1000000013LL
#define p1 7699LL
#define p2 129887LL
#define ord1 2566
#define ord2 64943
#define inv 191565459LL

using namespace std;

int main()
{
	int rem1[ord1] = { 1 }, rem2[ord2] = { 1 };
	for (int i = 1; i < ord1; i++)
		rem1[i] = rem1[i - 1] * 2 % p1;
	for (int i = 1; i < ord2; i++)
		rem2[i] = rem2[i - 1] * 2 % p2;

	ll n;
	cin >> n;

	int ans;
	if (n == 1)
		ans = 1;
	else
	{
		int x = n % 8;
		ll r1, r2;
		if (x == 0 || x == 1 || x == 7)
		{
			r1 = rem1[(n - 2) % ord1] + rem1[(n / 2 - 1) % ord1];
			r2 = rem2[(n - 2) % ord2] + rem2[(n / 2 - 1) % ord2];
		}
		else if (x == 2 || x == 6)
		{
			r1 = rem1[(n - 2) % ord1];
			r2 = rem2[(n - 2) % ord2];
		}
		else
		{
			r1 = rem1[(n - 2) % ord1] - rem1[(n / 2 - 1) % ord1];
			r2 = rem2[(n - 2) % ord2] - rem2[(n / 2 - 1) % ord2];
		}
		ans = ((r1 * p2 - r2 * p1) * inv) % MOD;
		if (ans < 0)
			ans += MOD;
	}
	cout << ans << endl;
	if (ans == 531069607)
	    cout << n;
    return 0;
}