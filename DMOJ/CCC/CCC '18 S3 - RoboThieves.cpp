#include <cstdio>
#include <algorithm>
#include <queue>
#include <functional>
#define pi pair<int, int>
#define ppi pair<int, pi>
using namespace std;

char grid[102][102];
int dist[102][102];
priority_queue<ppi, vector<ppi>, greater<ppi> > pq;

void attempt(int i, int j, int d) {
	if (dist[i][j] == -1)
		return;
	if (grid[i][j] == 'W')
		return;
	if (d < dist[i][j]) {
		dist[i][j] = d;
		pq.push(ppi(d, pi(i, j)));
	}
}

int main()
{
	int R, C, Si, Sj;
	scanf("%d%d", &R, &C);
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			scanf(" %c", &grid[i][j]);
			dist[i][j] = 1e9;
			if (grid[i][j] == 'S') {
				Si = i, Sj = j;
				dist[i][j] = 0;
			}
		}
	}

	// if seen by camera, mark dist[i][j] = -1
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (grid[i][j] == 'C') {
				dist[i][j] = -1;
				for (int k = i; k < R; k++) { //down
					if (grid[k][j] == '.')
						dist[k][j] = -1;
					else if (grid[k][j] == 'W')
						break;
				}
				for (int k = i; k > 0; k--) { //up
					if (grid[k][j] == '.')
						dist[k][j] = -1;
					else if (grid[k][j] == 'W')
						break;
				}
				for (int k = j; k > 0; k--) { //left
					if (grid[i][k] == '.')
						dist[i][k] = -1;
					else if (grid[i][k] == 'W')
						break;
				}
				for (int k = j; k < C; k++) { //right
					if (grid[i][k] == '.')
						dist[i][k] = -1;
					else if (grid[i][k] == 'W')
						break;
				}
			}
		}
	}

	if (dist[Si][Sj] == -1) { // start is seen by camera
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (grid[i][j] == '.')
					printf("-1\n");
			}
		}
		return 0;
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (grid[i][j] != 'W' && dist[i][j] != -1)
				pq.push(ppi(dist[i][j], pi(i, j)));
		}
	}

	while (!pq.empty()) {
		ppi p = pq.top(); pq.pop();
		int d = p.first;
		int i = p.second.first;
		int j = p.second.second;

		if (dist[i][j] == -1)
			continue;
		if (grid[i][j] == 'W')
			continue;

		if (grid[i][j] == 'U') {
			attempt(i - 1, j, d);
		}
		else if (grid[i][j] == 'D') {
			attempt(i + 1, j, d);
		}
		else if (grid[i][j] == 'L') {
			attempt(i, j - 1, d);
		}
		else if (grid[i][j] == 'R') {
			attempt(i, j + 1, d);
		}
		else {
			attempt(i - 1, j, d + 1);
			attempt(i + 1, j, d + 1);
			attempt(i, j - 1, d + 1);
			attempt(i, j + 1, d + 1);
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (grid[i][j] == '.') {
				if (dist[i][j] > 1e8)
					dist[i][j] = -1;
				printf("%d\n", dist[i][j]);
			}
		}
	}
    return 0;
}