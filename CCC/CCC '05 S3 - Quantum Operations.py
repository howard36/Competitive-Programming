import sys
input = sys.stdin.readline

def product(M,N):
    r_M = len(M)
    c_M = len(M[0])
    r_N = len(N)
    c_N = len(N[0])
    tensor = []
    for i_M in range(r_M):
        for i_N in range(r_N):
            row = []
            for j_M in range(c_M):
                subrow = []
                for j_N in range(c_N):
                    subrow.append(M[i_M][j_M] * N[i_N][j_N])
                row.extend(subrow)
            tensor.append(row)
    return tensor

n = int(input())
matrices = []
for i in range(n):
    r, c = (int(n) for n in input().split())
    M = []
    for _ in range(r):
        row = []
        for i in input().split():
            row.append(int(i))
        M.append(row)
    matrices.append(M)

tensor = matrices[0]
for i in range(1,n):
    tensor = product(tensor, matrices[i])

maximum = max((max(row) for row in tensor))
minimum = min((min(row) for row in tensor))
max_row = max((sum(row) for row in tensor))
min_row = min((sum(row) for row in tensor))
max_column = max((sum((tensor[i][j] for i in range(len(tensor)))) for j in range(len(tensor[0]))))
min_column = min((sum((tensor[i][j] for i in range(len(tensor)))) for j in range(len(tensor[0]))))
print(maximum)
print(minimum)
print(max_row)
print(min_row)
print(max_column)
print(min_column)