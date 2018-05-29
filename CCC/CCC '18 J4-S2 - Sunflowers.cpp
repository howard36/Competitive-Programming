#include <cstdio>
#include <vector>
#define vvi vector<vector<int> >
using namespace std;

int N;

vvi rotate(vvi a) {
	vvi b(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			b[j][N - 1 - i] = a[i][j];
		}
	}
	return b;
}

bool check(vvi v) {
	bool up = true;
	for (int i = 0; i < N-1; i++) {
		for (int j = 0; j < N; j++) {
			if (v[i][j] > v[i+1][j])
				up = false;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - 1; j++) {
			if (v[i][j] > v[i][j+1])
				up = false;
		}
	}
	return up;
}

void print(vvi v) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", v[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	scanf("%d", &N);
	vector<vector<int> > v1(N, vector<int>(N)), v2(N, vector<int>(N)), v3(N, vector<int>(N)), v4(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &v1[i][j]);
		}
	}
	v2 = rotate(v1);
	v3 = rotate(v2);
	v4 = rotate(v3);
	if (check(v1))
		print(v1);
	else if (check(v2))
		print(v2);
	else if (check(v3))
		print(v3);
	else
		print(v4);
    return 0;
}