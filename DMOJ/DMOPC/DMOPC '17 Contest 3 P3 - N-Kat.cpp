#include <cstdio>
#include <vector>
#include <algorithm>
#define pi pair<int,int>
using namespace std;

vector<pi> sum;
int sweet[21];
int N;

int calc(int i)
{
	int ans = 0;
	for (int j = 0; j < N; j++)
		if (i & (1 << j))
			ans += sweet[j];
	return ans;
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &sweet[i]);
	for (int i = 1; i < (1 << N); i++)
		sum.push_back(pi(calc(i), i));
	
	sort(sum.begin(), sum.end());

	int mindiff = sum[1].first-sum[0].first, index=0;
	for (int i = 1; i < sum.size() - 1; i++) {
		if (sum[i + 1].first - sum[i].first < mindiff) {
			mindiff = sum[i + 1].first - sum[i].first;
			index = i;
		}
	}

	int a = sum[index].second;
	int b = sum[index + 1].second;
	int c = a&b;
	a -= c;
	b -= c;

	for (int i = 0; i < N; i++)
		if (a & (1 << i))
			printf("%d ", i + 1);
	printf("\n");
	for (int i = 0; i < N; i++)
		if (b & (1 << i))
			printf("%d ", i + 1);

    return 0;
}