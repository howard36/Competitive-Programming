#include <cstdio>
#include <vector>
using namespace std;

int arr[100005];
vector<int> swaps;
int N;

void swap(int i)
{
	swaps.push_back(i);
	arr[i] ^= 1;
	if (i > 1)
		arr[i - 1] ^= 1;
	if (i < N)
		arr[i + 1] ^= 1;
}

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", &arr[i]);
	for (int i = 1; i < N; i++) {
		if (arr[i])
			swap(i + 1);
	}
	if (arr[N])
	{
		swap(1);
		for (int i = 1; i < N; i++)	{
			if (arr[i])
				swap(i + 1);
		}
	}
	
	printf("%d\n", swaps.size());
	for (int i:swaps)
		printf("%d\n", i);
    return 0;
}