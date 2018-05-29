import sys
input = sys.stdin.readline
from collections import defaultdict

def binaryToDecimal(numbers):
    binary = 0
    for i in range(2*n-1):
        binary += numbers[i] * 2**i
    return binary

grids = defaultdict(int)
n = int(input())
g = int(input())
for _ in range(g):
    grid = []
    columnCount = [0]*n
    for _ in range(n):
        row = input()
        grid.append(row.count('R') % 2)
        for i in range(n):
            if row[i] == 'R':
                columnCount[i] += 1
    for i in range(n):
        columnCount[i] %= 2
    grid.extend(columnCount)
    decimal = binaryToDecimal(grid)
    grids[decimal] += 1

similarCount = 0
for key in grids:
    similarCount += grids[key]*(grids[key]-1)//2

print(similarCount)