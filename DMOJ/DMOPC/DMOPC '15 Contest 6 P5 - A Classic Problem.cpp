#include <deque>
#include <cstdio>
#include <algorithm>
#define pi pair<int,int>
#define mp make_pair
using namespace std;

#define getchar() (*_pbuf ? *_pbuf++ : (_buf[fread_unlocked(_pbuf = _buf, 1, 16384, stdin)] = 0, *_pbuf++))
char _buf[16385], *_pbuf = _buf;

int read() {
    int c, o = 0;
    while ((c = getchar()) < '0');
    do o = o*10 + c - '0';
    while ((c = getchar()) >= '0');
    return o;
}

deque<pi> Max, Min;
int A[3000001];

int main()
{
	int n = read(), k = read();
	for (int i = 0; i < n; i++)
		A[i] = read();

	Max.push_back(mp(A[0], 0)); Min.push_back(mp(A[0], 0));
	int start = 0, end = 1; long long count = 0;
	while (end != n+1)
	{
		while (Max.front().first - Min.front().first <= k && end <= n)
		{
			count += end - start;
			while (!Max.empty() && A[end] >= Max.back().first) Max.pop_back();
			Max.push_back(mp(A[end], end));
			while (!Min.empty() && A[end] <= Min.back().first) Min.pop_back();
			Min.push_back(mp(A[end], end));
			++end;
		}
		while (Max.front().first - Min.front().first > k)
		{
			start = min(Max.front().second, Min.front().second) + 1;
			while (Max.front().second < start) Max.pop_front();
			while (Min.front().second < start) Min.pop_front();
		}
	}
	printf("%lld", count);
    return 0;
}