#include <cstdio>
#include <algorithm>
#include <vector>
#define pi pair<int,int>
using namespace std;

int n, orig[100001], target[100001], origPos[100001], targetPos[100001], frontCount[100001], backCount[100001];
vector<pi> sourness;

int shift(int i, bool front)
{
	int ans = 0;
	if (front)
		for (; i >= 1; i -= i&-i)
			ans += frontCount[i];
	else
		for (; i >= 1; i -= i&-i)
			ans += backCount[i];
	return ans;
}

void increment(int i, int inc, bool front)
{
	if (front)
		for (; i <= n; i += i&-i)
			frontCount[i] += inc;
	else
		for (; i <= n; i += i&-i)
			backCount[i] += inc;
}

inline bool comp(pi i, pi j) { return i.first < j.first; }

int main()
{
	scanf("%d", &n);
	int temp;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &temp);
		sourness.push_back(make_pair(temp, i));
	}
	sort(sourness.begin(), sourness.end(), comp);
	for (int i=0; i<n;i++)
	{
		pi p = sourness[i];
		orig[p.second] = i+1;
		origPos[i+1] = p.second;
	}
	sourness.clear();
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &temp);
		sourness.push_back(make_pair(temp, i));
	}
	sort(sourness.begin(), sourness.end(), comp);
	for (int i = 0; i < n; i++)
	{
		pi p = sourness[i];
		target[p.second] = i+1;
		targetPos[i+1] = p.second;
	}

	int lastPos = -1, maxLength = 0, length = 0, maxX, x, pos;
	for (int i = 1; i <= n; i++)
	{
		x = target[i];
		pos = origPos[x];
		if (pos > lastPos)
		{
			++length;
			if (length > maxLength)
			{
				maxLength = length;
				maxX = x;
			}
		}
		else
			length = 1;
		lastPos = pos;
	}

	printf("%d", n - maxLength);

	int index = targetPos[maxX];
	vector<int> front, back;
	for (int i = index - maxLength; i > 0; i--)
		front.push_back(target[i]);
	for (int i = index + 1; i <= n; i++)
		back.push_back(target[i]);

	for (int i : front)
	{
		int realPos = origPos[i] + shift(n + 1 - origPos[i], true);
		printf("\nF %d", realPos);
		increment(n + 1 - origPos[i], 1, true);
	}
	for (int i : back)
	{
		int realPos = origPos[i] + shift(n + 1 - origPos[i], true) - shift(origPos[i], false);
		printf("\nB %d", realPos);
		increment(origPos[i], 1, false);
	}

    return 0;
}