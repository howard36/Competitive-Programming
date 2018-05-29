#include <cstdio>
#include <algorithm>
#include <unordered_map>
#define pi pair<int,int>
#define mp make_pair
using namespace std;

#define getchar() (*_pinp?*_pinp++:(_inp[fread(_pinp=_inp, 1, 4096, stdin)]='\0', *_pinp++))
char _inp[4097], *_pinp = _inp;
#define scan(x) do{while((x=getchar())<'-'); _ssign=x=='-'; if(_ssign) while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0'); x=_ssign?-x:x;}while(0)
char _; bool _ssign;

unordered_map<int, int> X, Y, left;
pi points[100000];

bool comp(pi x, pi y)
{
	if (x.first != y.first)
		return (x.first < y.first);
	else
		return (x.second < y.second);
}

int main()
{
	int n, x, y;
	scan(n);
	for (int i = 0; i < n; i++)
	{
		scan(x); scan(y);
		points[i] = mp(x, y);
		++X[x];
		++Y[y];
	}
	sort(points, points + n, comp);

	int l, r, t, b = 0, lastx = points[0].first;
	long long ans = 0;
	for (int i = 0; i < n; i++)
	{
		x = points[i].first, y = points[i].second;
		if (x != lastx)
		{
			lastx = x;
			b = 0;
		}
		else
			++b;
		l = left[y]; r = Y[y] - l - 1;
		t = X[x] - b - 1;
		ans += 2LL * l*r*t*b;
		++left[y];
	}
	printf("%lld", ans);
    return 0;
}