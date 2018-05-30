#include <cstdio>
#include <utility>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;

ll a[1000001], BIT[1000002], b[1000001];
int N, P;

void add(int x)
{
	for (; x <= N + 1; x += x&-x)
		BIT[x]++;
}

ll sum(int x)
{
	ll ans = 0;
	for (; x > 0; x -= x&-x)
		ans += BIT[x];
	return ans;
}

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%lld", &a[i]);
	scanf("%d", &P);
	for (int i = 1; i <= N; i++)
		a[i] += a[i - 1] - P;
	memcpy(b, a, (N + 1) * sizeof(a[0]));

	sort(b, b + N + 1);
	ll count = 0;
	for (int i = 0; i <= N; i++)
	{
		int comp = (lower_bound(b, b + N + 1, a[i]) - b) + 1;
		count += sum(comp);
		add(comp);
	}
	printf("%lld", count);
    return 0;
}