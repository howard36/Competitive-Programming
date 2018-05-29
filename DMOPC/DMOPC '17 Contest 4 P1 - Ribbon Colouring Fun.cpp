#include <cstdio>

int arr[100005];

int main()
{
	int N, Q, x, y;
	scanf("%d%d", &N, &Q);
	while (Q--) {
		scanf("%d%d", &x, &y);
		arr[x]++;
		arr[y]--;
	}
	int sum = 0, purple = 0, blue = 0;
	for (int i = 0; i < N; i++) {
		sum += arr[i];
		if (sum)
			blue++;
		else
			purple++;
	}
	printf("%d %d", purple, blue);
    return 0;
}