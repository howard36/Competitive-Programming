#include <cstdio>
#include <cstring>
int grid[40][40], count[40];

int main()
{
	int N;
	scanf("%d", &N);
	char x;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			scanf(" %c", &x);
			if (x < 'A')
				grid[r][c] = x - '0';
			else
				grid[r][c] = x - 'A' + 10;
		}
	}
	bool latin = true;
	for (int r = 0; r < N; r++) {
		memset(count, 0, sizeof count);
		for (int c = 0; c < N; c++) {
			if (count[grid[r][c]] == 0)
				count[grid[r][c]] = 1;
			else {
				latin = false;
				break;
			}
		}
	}
	for (int c = 0; c < N; c++) {
		memset(count, 0, sizeof count);
		for (int r = 0; r < N; r++) {
			if (count[grid[r][c]] == 0)
				count[grid[r][c]] = 1;
			else {
				latin = false;
				break;
			}
		}
	}
	if (latin) {
		bool reduced = true;
		for (int c = 0; c < N; c++) {
			if (grid[0][c] != c)
				reduced = false;
		}
		for (int r = 0; r < N; r++) {
			if (grid[r][0] != r)
				reduced = false;
		}
		if (reduced)
			printf("Reduced");
		else
			printf("Latin");
	}
	else {
		printf("No");
	}
    return 0;
}