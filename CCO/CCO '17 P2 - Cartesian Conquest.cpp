#include <cstdio>
#include <algorithm>
#include <unordered_map>
#include <utility>
using namespace std;
typedef long long ll;

unordered_map<ll, int> storedMin = {
	{ 0, 0 }
};
unordered_map<ll, int> storedMax = {
	{ 0, 0 }
};

ll PairToLL(ll i, ll j) { return i * 100000001 + j; }

int minimum(int low, int high)
{
	if (low > high)
		swap(low, high);
	ll l = PairToLL(low, high);
	if (storedMin.find(l) != storedMin.end())
		return storedMin[l];

	int ans;
	if (high == 2 * low)
		ans = 1;
	else if (high >= 3 * low)
	{
		int times = (high - low) / (2 * low);
		ans = times + minimum(high - times * 2 * low, low);
	}
	else if (low % 2 == 1)
	{
		if (high > 2 * low)
		{
			int times = high / (2 * low);
			ans = times + minimum(high - times * 2 * low, low);
		}
		else
			ans = 1 + minimum(low - high / 2, high);
	}
	else if (high % 2 == 1)
	{
		if (high > 2 * low)
		{
			int a = minimum(low, high - low / 2);
			int b = minimum(low, high - 2 * low);
			ans = 1 + min(a, b);
		}
		else
			ans = 1 + minimum(low, high - low / 2);
	}
	else
	{
		int a = minimum(low, high - low / 2);
		if (high > 2 * low)
		{
			int b = minimum(low, high - 2 * low);
			ans = 1 + min(a, b);
		}
		else
		{
			int c = minimum(low - high / 2, high);
			ans = 1 + min(a, c);
		}
	}
	storedMin[l] = ans;
	return ans;
}

int maximum(int low, int high)
{
	if (low > high)
		swap(low, high);
	ll l = PairToLL(low, high);
	if (storedMax.find(l) != storedMax.end())
		return storedMax[l];

	int ans;
	if (low == 0 || high == 0)
		ans = 0;
	else if (low % 2 == 1)
	{
		if (high > 2 * low)
		{
			int times = high / (2 * low);
			ans = times + maximum(high - times * 2 * low, low);
		}
		else
			ans = 1 + maximum(low - high / 2, high);
	}
	else if (high % 2 == 1)
	{
		int times = high / (low / 2) - 3;
		if (times <= 0)
			times = 1;
		ans = times + maximum(low, high - times*(low / 2));
	}
	else if (high > 2 * low)
	{
		int times = high / (low / 2) - 3;
		if (times <= 0)
			times = 1;
		ans = times + maximum(low, high - times*(low / 2));
	}
	else
	{
		int a = maximum(low, high - low / 2);
		int c = maximum(low - high / 2, high);
		ans = 1 + max(a, c);
	}
	storedMax[l] = ans;
	return ans;
}


int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	int big = maximum(n, m);
	if (n % 4096 == 0 && m % 4096 == 0)
	{
		n /= 1024;
		m /= 1024;
	}
	int small = minimum(n, m);
	printf("%d %d", small, big);
	return 0;
}