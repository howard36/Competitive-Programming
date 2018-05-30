#define ll long long
#define pi pair<int, int>
#include <queue>
#include <cstdio>
using namespace std;

ll x[1000006], psa[1000006], start[1000006], dp[1000006];
ll N, a, b, c;
deque<pi> depend;

ll f(int l, int r) {
	ll x = psa[r] - psa[l];
	return a * x * x + b * x + c;
}

int main()
{
	scanf("%lld %lld %lld %lld", &N, &a, &b, &c);
	for (int i = 1; i <= N; i++) {
		scanf("%lld", &x[i]);
		psa[i] = psa[i - 1] + x[i];
		start[i] = N + 1;
	}
	psa[N + 1] = psa[N];
	int curDepend = 0;
	for (int i = 1; i <= N; i++) {
		if (!depend.empty() && i >= depend.front().second) {
			curDepend = depend.front().first;
			depend.pop_front();
		}
		dp[i] = dp[curDepend] + f(curDepend, i);
		// binary search for first number that depends on i
		int lo = i + 1, hi = N + 1;
		while (lo < hi) {
			int mid = (lo + hi) / 2;
			if (dp[i] + f(i, mid) > dp[i - 1] + f(i - 1, mid)) // better for mid to depend on i than i-1
				hi = mid;
			else
				lo = mid + 1;
		}
		while (!depend.empty() && depend.back().second > lo)
			depend.pop_back();
		depend.push_back(pi(i, lo));
	}
	printf("%lld", dp[N]);
    return 0;
}