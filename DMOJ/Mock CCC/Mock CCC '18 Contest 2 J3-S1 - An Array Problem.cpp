#include <cstdio>
#include <algorithm>
using namespace std;
long long nums[100];

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &nums[i]);
		if (nums[i] < 0)
			nums[i] = 0;
	}
	sort(nums, nums + N);
	long long sum = 0;
	for (int i = 0; i < N - 1; i++) {
		sum += nums[i];
	}
	if (sum < nums[N - 1])
		printf("%lld", sum);
	else
		printf("%lld", (sum + nums[N - 1]) / 2);
    return 0;
}