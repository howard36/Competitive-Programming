#include <cstdio>
#include <stack>
#define ll long long
#define pli pair<ll,int>
#define mp make_pair
using namespace std;

ll height[400001];
stack<pli> s;

int main()
{
	int n; ll count = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lld", &height[i]);
	s.push(mp(height[0], 1));
	for (int i = 1; i < n; i++)
	{
		int equal = 1;
		while (!s.empty() && s.top().first <= height[i])
		{
			count += s.top().second;
			if (s.top().first == height[i])
				equal = s.top().second + 1;
			s.pop();
		}
		if (!s.empty())
			++count;
		s.push(mp(height[i], equal));
	}
	printf("%lld", count);
    return 0;
}