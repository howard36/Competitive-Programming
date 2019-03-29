#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll grid[3][3];
int done[3][3];

void fillrow(int x) {
	int sum = 0;
	for (int i = 0; i < 3; i++) {
		sum += done[x][i];
	}
	if (sum == 2) {
		if (done[x][0] == 0) {
			grid[x][0] = 2 * grid[x][1] - grid[x][2];
			done[x][0] = 1;
		}
		else if (done[x][2] == 0) {
			grid[x][2] = 2 * grid[x][1] - grid[x][0];
			done[x][2] = 1;
		}
		else {
			grid[x][1] = (grid[x][0] + grid[x][2]) / 2;
			done[x][1] = 1;
		}
	}
}

void fillcol(int y) {
	int sum = 0;
	for (int i = 0; i < 3; i++) {
		sum += done[i][y];
	}
	if (sum == 2) {
		if (done[0][y] == 0) {
			grid[0][y] = 2 * grid[1][y] - grid[2][y];
            done[0][y] = 1;
		}
		else if (done[2][y] == 0) {
			grid[2][y] = 2 * grid[1][y] - grid[0][y];
            done[2][y] = 1;
		}
		else {
			grid[1][y] = (grid[0][y] + grid[2][y]) / 2;
            done[1][y] = 1;
		}
	}
}

void fill() {
	for (int i = 0; i < 3; i++) {
		fillrow(i);
	}
	for (int i = 0; i < 3; i++) {
		fillcol(i);
	}
	for (int i = 0; i < 3; i++) {
		fillrow(i);
	}
	for (int i = 0; i < 3; i++) {
		fillcol(i);
	}
	for (int i = 0; i < 3; i++) {
		fillrow(i);
	}
	for (int i = 0; i < 3; i++) {
		fillcol(i);
	}
}

bool alldone() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (done[i][j] == 0)
				return false;
		}
	}
	return true;
}

bool rowdone(int x) {
	for (int i = 0; i < 3; i++) {
		if (done[x][i] == 0)
			return false;
	}
	return true;
}

int main() {
	// freopen("data.txt", "r", stdin);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			string s;
			cin >> s;
			if (s != "X") {
				done[i][j] = 1;
				grid[i][j] = stoi(s);
			}
		}
	}

	fill();

	if (!alldone()) {
		if (!rowdone(1)) {
			ll filler = 0;
			for (int i = 0; i < 3; i++) {
				if (done[1][i])
					filler = grid[1][i];
			}
			for (int i = 0; i < 3; i++) {
				grid[1][i] = filler;
				done[1][i] = 1;
			}
		}
		else {
			ll filler = 0;
			for (int i = 0; i < 3; i++) {
				if (done[0][i])
					filler = grid[0][i];
			}
			for (int i = 0; i < 3; i++) {
				grid[0][i] = filler;
				done[0][i] = 1;
			}
		}
	}

	fill();

	if (!alldone()) {
		ll filler = 0;
		for (int i = 0; i < 3; i++) {
			if (done[0][i])
				filler = grid[0][i];
		}
		for (int i = 0; i < 3; i++) {
			grid[0][i] = filler;
			done[0][i] = 1;
		}
	}

	fill();
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%lld ", grid[i][j]);
		}
		printf("\n");
	}
}