#include <cstdio>
#include <vector>
#include <algorithm>
#define Matrix vector<vector<int> >
using namespace std;

vector<Matrix> Matrices;
vector<int> rowsum, colsum;

Matrix tensor(Matrix A, Matrix B) {
	int Ar = A.size(), Ac = A[0].size(), Br = B.size(), Bc = B[0].size();
	Matrix T(Ar*Br, vector<int>(Ac*Bc));
	for (int ar = 0; ar < Ar; ar++) {
		for (int ac = 0; ac < Ac; ac++) {
			for (int br = 0; br < Br; br++) {
				for (int bc = 0; bc < Bc; bc++) {
					T[ar*Br + br][ac*Bc + bc] = A[ar][ac] * B[br][bc];
				}
			}
		}
	}
	return T;
}

int main()
{
	int N, R, C;
	scanf("%d%d%d", &N, &R, &C);
	Matrix current(R, vector<int>(C));
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			scanf("%d", &current[r][c]);
		}
	}
	Matrix three;
	for (int i = 1; i < N; i++) {
		scanf("%d%d", &R, &C);
		Matrix two(R, vector<int>(C));
		for (int r = 0; r < R; r++) {
			for (int c = 0; c < C; c++) {
				scanf("%d", &two[r][c]);
			}
		}
		current = tensor(current, two);
	}
	R = current.size(), C = current[0].size();
	int M = -1e9, m = 1e9;
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			M = max(M, current[r][c]);
			m = min(m, current[r][c]);
		}
	}
	for (int r = 0; r < R; r++) {
		int sum = 0;
		for (int c = 0; c < C; c++) {
			sum += current[r][c];
		}
		rowsum.push_back(sum);
	}
	for (int c = 0; c < C; c++) {
		int sum = 0;
		for (int r = 0; r < R; r++) {
			sum += current[r][c];
		}
		colsum.push_back(sum);
	}
	sort(rowsum.begin(), rowsum.end());
	sort(colsum.begin(), colsum.end());
	printf("%d\n%d\n%d\n%d\n%d\n%d", M, m, rowsum[R - 1], rowsum[0], colsum[C - 1], colsum[0]);
}