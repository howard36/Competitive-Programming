#include <cstdio>
#include <unordered_map>
#define ll long long
using namespace std;

unordered_map <ll, int> color;

ll hash1(ll a, ll b) { return a * 123456789LL + b; }

int main()
{
	int N, Q;
	scanf("%d %d", &N, &Q);
	for (int i = 0; i < N; i++)
	{
		ll x, y; int v;
		scanf("%lld %lld %d", &x, &y, &v);
		color[hash1(x, y)] += v;
	}
	for (int i = 0; i < Q; i++)
	{
		ll r, c, ans = 0LL;
		scanf("%lld %lld", &r, &c);
		for (int j = 0; 1 << j <= r; j++)
			for (int k = 0; 1 << k <= c; k++)
				ans += color[hash1((r&((1 << j) - 1)) | (1 << j), (c&((1 << k) - 1)) | (1 << k))];
		printf("%lld\n", ans);
	}
    return 0;
}