#include <cstdio>

int grid[102][102];

int main()
{
	int N;
	while (true) {
		scanf("%d", &N);
		if (N == 0)
			break;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				scanf("%d", &grid[i][j]);
			}
		}
		bool works = true;
		for (int x = 1; x <= N; x++) {
			for (int y = 1; y <= N; y++) {
				for (int z = 1; z <= N; z++) {
					if (grid[x][grid[y][z]] != grid[grid[x][y]][z])
						works = false;
				}
			}
		}
		if (!works) {
			printf("no\n");
			continue;
		}
		int identity = 0;
		for (int i = 1; i <= N; i++) {
			bool isidentity = true;
			for (int x = 1; x <= N; x++) {
				if (grid[x][i] != x || grid[i][x] != x)
					isidentity = false;
			}
			if (isidentity)
				identity = i;
		}
		if (identity == 0) {
			printf("no\n");
			continue;
		}
		bool inverses = true;
		for (int x = 1; x <= N; x++) {
			bool inverse = false;
			for (int y = 1; y <= N; y++) {
				if (grid[x][y] == identity && grid[y][x] == identity)
					inverse = true;
			}
			if (!inverse)
				inverses = false;
		}
		if (inverses)
			printf("yes\n");
		else
			printf("no\n");
	}
    return 0;
}