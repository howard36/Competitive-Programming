#include <bits/stdc++.h>
#define pi pair<int, int>
using namespace std;

int grid[30004][30];
vector<pi> path[30];
int r, c;

pi next(pi p) {
	int x = p.first, y = p.second;
	if (x == r - 1 || grid[x + 1][y] == 1)
		return pi(-1, -1);
	if (grid[x + 1][y] == 0)
		return pi(x + 1, y);
	if (y > 0 && grid[x][y - 1] == 0 && grid[x + 1][y - 1] == 0)
		return pi(x + 1, y - 1);
	if (y < c - 1 && grid[x][y + 1] == 0 && grid[x + 1][y + 1] == 0)
		return pi(x + 1, y + 1);
	return pi(-1, -1);
}

int main() {
	char chr;
	scanf("%d %d", &r, &c);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			scanf(" %c", &chr);
			grid[i][j] = (chr == 'X');
		}
	}
	for (int i = 0; i < c; i++) {
		for (pi p = pi(0, i); p.first != -1; p = next(p)) {
			path[i].push_back(p);
		}
	}
	int q;
	scanf("%d", &q);
	while (q--) {
        int x;
        scanf("%d", &x);
        pi p = path[x-1][path[x-1].size()-1];
        grid[p.first][p.second] = 2;
        for (int i = 0; i<c; i++){
            if (path[i][path[i].size()-1] == p){
                path[i].pop_back();
            }
        }
	}
    for (int i = 0; i<r; i++){
        for (int j = 0; j<c; j++){
            if (grid[i][j] == 0)
                printf(".");
            else if (grid[i][j] == 1)
                printf("X");
            else
                printf("O");
        }
        printf("\n");
    }
}