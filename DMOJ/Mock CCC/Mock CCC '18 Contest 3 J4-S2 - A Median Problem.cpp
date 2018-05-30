#include <cstdio>
#include <algorithm>
using namespace std;

int temp[100];
int medians[100];

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &temp[j]);
		}
		sort(temp, temp + N);
		medians[i] = temp[(N + 1) / 2];
	}
	sort(medians, medians + N);
	printf("%d", medians[(N + 1) / 2]);
    return 0;
}