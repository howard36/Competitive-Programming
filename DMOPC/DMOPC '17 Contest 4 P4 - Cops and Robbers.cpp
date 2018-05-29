#include <cstdio>

int a[1000006], b[1000006], used[1000006];

int main()
{
	int N; 
	scanf("%d", &N);
	bool different = false;
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
		if (a[i] != a[0])
			different = true;
	}
	if (!different) {
		printf("-1");
		return 0;
	}
	for (int i = 1; i < N; i++) {
		if (a[i] != a[i - 1] && !used[a[i-1]]) {
			b[i] = a[i - 1];
			used[a[i - 1]] = 1;
		}
	}
	if (a[0] != a[N - 1] && !used[a[N - 1]]) {
		b[0] = a[N - 1];
		used[a[N - 1]] = 1;
	}
	int ptr = 1;
	for (int i = 0; i < N; i++) {
		if (b[i] == 0) {
			while (used[ptr])
				++ptr;
			b[i] = ptr;
			used[ptr] = 1;
		}
	}
	for (int i = 0; i < N; i++) {
		printf("%d ", b[i]);
	}
    return 0;
}