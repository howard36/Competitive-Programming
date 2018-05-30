#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int grid[100][100];
vector<int> list;

int counter;

void dfs(int r, int c) {
	if (r < 0 || c < 0)
		return;
	if (grid[r][c] == 1) {
		grid[r][c] = 2;
		counter++;
		dfs(r + 1, c);
		dfs(r, c + 1);
		dfs(r - 1, c);
		dfs(r, c - 1);
	}
}

int main()
{
	int amount, R, C;
	char chr;
	scanf("%d%d%d", &amount, &R, &C);
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			scanf(" %c", &chr);
			if (chr == 'I')
				grid[r][c] = 2;
			else
				grid[r][c] = 1;
		}
	}
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			if (grid[r][c] == 1) {
				counter = 0;
				dfs(r, c);
				list.push_back(counter);
			}
		}
	}
	sort(list.begin(), list.end(), greater<int>());
	int room = 0;
	for (; room < list.size(); room++) {
		if (list[room] <= amount) {
			amount -= list[room];
		}
		else
			break;
	}
	printf("%d rooms, %d square metre(s) left over", room, amount);
    return 0;
}