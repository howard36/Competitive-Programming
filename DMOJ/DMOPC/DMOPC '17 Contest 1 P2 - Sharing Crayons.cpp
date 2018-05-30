#include <cstdio>
#include <unordered_map>
using namespace std;

unordered_map<int, int> cnt;
int N, M, x, sum = 0;
long long ans = 0LL;
int main()
{
	scanf("%d %d", &N, &M);
	cnt[0] = 1;
	while (N--)
	{
		scanf("%d", &x);
		sum = (sum + x) % M;
		cnt[sum]++;
	}
	for (auto i : cnt)
		ans += 1LL * i.second * (i.second - 1) / 2;
	printf("%lld", ans);
    return 0;
}