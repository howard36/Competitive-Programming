#include <cstdio>

int arr[1003], pos[1003];

int main()
{
	int N;
	for (int asdf = 0; asdf < 10; asdf++) {
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%d", &arr[i]);
			pos[arr[i]] = i;
		}
		int next = N;
		for (int i = N - 1; i >= 0; i--) {
			if (arr[i] == next)
				next--;
		}
		int count = 0;
		for (; next > 0; next--) {
			count += pos[next];
			for (int i = pos[next] - 1; i >= 0; i--) {
				arr[i + 1] = arr[i];
				pos[arr[i]] = i + 1;
			}
			arr[0] = next;
		}
		printf("%d\n", count);
	}
    return 0;
}