#include <cstdio>
#include <algorithm>
using namespace std;

int arr[1000];

int main()
{
	int N, X;
	scanf("%d%d", &N, &X);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + N);
	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			for (int k = j + 1; k < N; k++) {
				if (arr[j] == X)
					count++;
			}
		}
	}
	printf("%d", count);
    return 0;
}