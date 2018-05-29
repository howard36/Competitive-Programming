#include <cstdio>
#define ll long long
#include <algorithm>
using namespace std;

ll c[1000006];

int main()
{
	int K, N;
	scanf("%d %d", &K, &N);
	if (K > N + 1) {
		printf("-1");
		return 0;
	}
	for (int i = 1; i <= N; i++) {
		scanf("%lld", &c[i]);
	}
	if (K == 1) {
		printf("%lld", max(c[1], c[2]));
		return 0;
	}
	ll cool = c[K], maxcool = c[K];
	for (int i = K; i > 2; i -= 2) {
		cool += c[i - 1] + c[i - 2] - c[i];
		if (cool > maxcool)
			maxcool = cool;
	}
	if (K % 2 == 0) {
		cool += c[1] - c[2];
		if (cool > maxcool)
			maxcool = cool;
	}
	printf("%lld", maxcool);
    return 0;
}