import sys
sys.setrecursionlimit(5000)

n, m = [int(n) for n in input().split()]
sq1 = [int(n) for n in input().split()]
sq2 = [int(n) for n in input().split()]

array = []
for i in range(n+1):
    array.append([-1]*(m+1))

for x in range(n+1):
    array[x][0] = 0
for y in range(m+1):
    array[0][y] = 0

def LCS(x, y):
    if array[x][y] == -1:
        if sq1[x-1] == sq2[y-1]:
            array[x][y] = LCS(x-1, y-1)+1
        else:
            array[x][y] = max(LCS(x-1, y), LCS(x, y-1))
    return array[x][y]

print(LCS(n,m))