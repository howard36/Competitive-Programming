#include <bits/stdc++.h>
using namespace std;

int a[5], dp[301][301][301], dp2[301][301];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i<n; i++)
		cin >> a[i];

	for (int x = 0; x <= 300; x++) {
		for (int y = 0; y <= 300; y++) {
			for (int z = 0; z <= 300; z++) {
				if (dp[x][y][z] == 0) {
					for (int i = 1; i+max(x, max(y, z)) <= 300; i++)
						dp[x+i][y+i][z+i] = 1;
					for (int i = 1; i+x <= 300; i++)
						dp[x+i][y][z] = 1;
					for (int i = 1; i+y <= 300; i++)
						dp[x][y+i][z] = 1;
					for (int i = 1; i+z <= 300; i++)
						dp[x][y][z+i] = 1;
				}
			}
		}
	}

	for (int x = 0; x <= 300; x++) {
		for (int y = 0; y <= 300; y++) {
			if (dp2[x][y] == 0) {
				for (int i = 1; i+max(x, y) <= 300; i++)
					dp2[x+i][y+i] = 1;
				for (int i = 1; i+x <= 300; i++)
					dp2[x+i][y] = 1;
				for (int i = 1; i+y <= 300; i++)
					dp2[x][y+i] = 1;
			}
		}
	}


	if (n == 1) {
		if (a[0] == 0)
			cout << "BitAryo" << endl;
		else
			cout << "BitLGM" << endl;
	}
	else if (n == 2) {
		if (dp2[a[0]][a[1]])
			cout << "BitLGM" << endl;
		else
			cout << "BitAryo" << endl;
	}
	else {
		if (dp[a[0]][a[1]][a[2]])
			cout << "BitLGM" << endl;
		else
			cout << "BitAryo" << endl;

	}
}
