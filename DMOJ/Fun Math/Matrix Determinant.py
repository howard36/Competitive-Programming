import copy
import sys

n = int(sys.stdin.readline())
matrix = []
for _ in range(n):
    row = []
    for m in sys.stdin.readline().split():
        row.append(int(m))
    matrix.append(row)

def det(M, n):
    if n == 1:
        return M[0][0]
    else:
        column0 = []
        for i in range(n):
            column0.append(M[i].pop(0))
        determinant = 0
        for i in range(n):
            submatrix = copy.deepcopy(M)
            del submatrix[i]
            if i % 2 == 0:
                determinant += (column0[i]*det(submatrix, n-1)) % (10**9+7)
            else:
                determinant -= (column0[i]*det(submatrix, n-1)) % (10**9+7)
        return determinant

print(det(matrix, n))