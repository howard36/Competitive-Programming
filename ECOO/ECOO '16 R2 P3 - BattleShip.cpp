#include <cstdio>
#include <algorithm>
using namespace std;
int grid[102][102];

int main()
{
	int S, L;
	char chr;
	for (int i = 0; i < 10; i++) {
		scanf("%d%d", &S, &L);
		for (int r = 0; r < S; r++) {
			for (int c = 0; c < S; c++) {
				scanf(" %c", &chr);
				if (chr == '.')
					grid[r][c] = 0;
				else if (chr == 'h')
					grid[r][c] = 1;
				else
					grid[r][c] = -1;
			}
		}
		int count = 0;
		// horizontal
		for (int r = 0; r < S; r++) {
			for (int c = 0; c < S - L + 1; c++) {
				if (r == 1 && c == 0) {
					int x = 0;
				}
				bool good = true;
				for (int k = 0; k < L; k++) {
					if (grid[r][c + k] == -1)
						good = false;
				}
				if (r > 0) {
					for (int k = 0; k < L; k++) {
						if (grid[r - 1][c + k] == 1)
							good = false;
					}
				}
				if (r < S - 1) {
					for (int k = 0; k < L; k++) {
						if (grid[r + 1][c + k] == 1)
							good = false;
					}
				}
				if (c > 0) {
					if (grid[r][c - 1] == 1)
						good = false;
					if (r > 0 && grid[r - 1][c - 1] == 1)
						good = false;
					if (r < S - 1 && grid[r + 1][c - 1] == 1)
						good = false;
				}
				if (c < S - L) {
					if (grid[r][c + L] == 1)
						good = false;
					if (r > 0 && grid[r - 1][c + L] == 1)
						good = false;
					if (r < S - 1 && grid[r + 1][c + L] == 1)
						good = false;
				}
				if (good)
					count++;
			}
		}

		for (int r = 0; r < S; r++) {
			for (int c = r + 1; c < S; c++) {
				swap(grid[r][c], grid[c][r]);
			}
		}

		// vertical
		for (int r = 0; r < S; r++) {
			for (int c = 0; c < S - L + 1; c++) {
				if (r == 1 && c == 0) {
					int x = 0;
				}
				bool good = true;
				for (int k = 0; k < L; k++) {
					if (grid[r][c + k] == -1)
						good = false;
				}
				if (r > 0) {
					for (int k = 0; k < L; k++) {
						if (grid[r - 1][c + k] == 1)
							good = false;
					}
				}
				if (r < S - 1) {
					for (int k = 0; k < L; k++) {
						if (grid[r + 1][c + k] == 1)
							good = false;
					}
				}
				if (c > 0) {
					if (grid[r][c - 1] == 1)
						good = false;
					if (r > 0 && grid[r - 1][c - 1] == 1)
						good = false;
					if (r < S - 1 && grid[r + 1][c - 1] == 1)
						good = false;
				}
				if (c < S - L) {
					if (grid[r][c + L] == 1)
						good = false;
					if (r > 0 && grid[r - 1][c + L] == 1)
						good = false;
					if (r < S - 1 && grid[r + 1][c + L] == 1)
						good = false;
				}
				if (good)
					count++;
			}
		}
		printf("%d\n", count);
	}
    return 0;
}