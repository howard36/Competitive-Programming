#include <cstdio>
int arr[1003];

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	int inversions = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (arr[i] > arr[j])
				inversions++;
		}
	}
	printf("%d", inversions);
    return 0;
}