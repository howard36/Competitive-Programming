#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

vector<int> nums;

int main()
{
	int N, x;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &x);
		nums.push_back(x);
	}
	sort(nums.begin(), nums.end());
	int diff = nums[2] - nums[0];
	for (int i = 0; i < N - 2; i++) {
		diff = min(diff, nums[i + 2] - nums[i]);
	}
	printf("%.1lf", (double)diff / 2);
	return 0;
}