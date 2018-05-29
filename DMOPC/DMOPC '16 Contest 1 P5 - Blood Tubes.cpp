#include <cstdio>
#include <algorithm>
#define getchar() (*_pinp?*_pinp++:(_inp[fread(_pinp=_inp, 1, 4096, stdin)]='\0', *_pinp++))
char _inp[4097], *_pinp=_inp;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;

int BIT[500001];
int N;

int sum(int i)
{
	int ans = 0;
	for (; i >= 1; i -= i&-i)
		ans += BIT[i];
	return ans;
}

void increment(int i, int inc)
{
	for (; i <= N; i += i&-i)
		BIT[i] += inc;
}

int main()
{
	scan(N);
	long long count = 0; int less, num;
	for (int i = 0; i < N; i++)
	{
		scan(num);
		less = sum(num);
		count += min(less, i - less);
		increment(num, 1);
	}
	printf("%lld", count);
    return 0;
}