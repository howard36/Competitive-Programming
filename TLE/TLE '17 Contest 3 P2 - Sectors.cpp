#include <unordered_map>
#include <cstdio>
using namespace std;

unordered_map<int, int> map;
int main()
{
	int S, K, s, k;
	long long count = 1LL;
	scanf("%d%d", &S, &K);
	for (int i = 0; i < S; i++)
	{
		scanf("%d", &s);
		map[s] = i;
	}
	scanf("%d", &k);
	int last = map[k];
	for (int i = 1; i < K; i++)
	{
		scanf("%d", &k);
		count += abs(last - map[k]);
		last = map[k];
	}
	printf("%lld", count);
    return 0;
}