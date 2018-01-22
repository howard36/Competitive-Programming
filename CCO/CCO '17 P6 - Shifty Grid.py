import sys
input = sys.stdin.readline

def shift(t,rc,shiftAmount): #rc between 0 and n-1 or m-1
    temp = []
    if t==1:
        shiftAmount %= m
        moves.append((t,rc+1,shiftAmount))
        for j in range(m):
            temp.append(array[rc][(j-shiftAmount)%m])
        for j in range(m):
            array[rc][j] = temp[j]
            pos[temp[j]] = (rc,j)
    else:
        shiftAmount %= n
        moves.append((t,rc+1,shiftAmount))
        for i in range(n):
            temp.append(array[(i-shiftAmount)%n][rc])
        for i in range(n):
            array[i][rc] = temp[i]
            pos[temp[i]] = (i,rc)

def solveRow(row):
    for target in range(row*m,(row+1)*m-1):
        shift(1, pos[target][0], -1-pos[target][1]) #moves target to last column
        if pos[target][0] == row and target != row*m: #if target already in row, move it out of row
            shift(2, m-1, 1)
            shift(1, row, -2-pos[target-1][1])
        shift(2, m-1, row-pos[target][0]) #moves target to correct row
        shift(1, row, -1) #inserts target in row

def solveLastColumn():
    for target in range(2*m-1, m*n-m, m):
        if pos[target][1] != m-1: #target in last row, second-last column
            shift(2, m-1, -2-pos[target-m][0])
            shift(1, n-1, 1)
            shift(2, m-1, -1)
            shift(1, n-1, -1)
            continue
        shift(2, m-1, -1-pos[target][0]) #moves target to last row
        shift(1, n-1, 1) #stores target in last row temporarily
        shift(2, m-1, -2-pos[target-m][0]) #moves target-m to second-last row
        shift(1, n-1, -1) #inserts target under target-m
    shift(2, m-1, -pos[m-1][0]) #aligns column so that m-1 is in correct place

def jump2Left(target): #changes ..., x, y, target, ... to ... target, x, y, ...
    r = pos[target][0] #without changing anything else in the array
    c = pos[target][1]-1
    if c <= 0: c += m
    shift(2, c, 1)
    shift(1, r, -1)
    shift(2, c, -1)
    shift(1, r, 2)
    shift(2, c, 1)
    shift(1, r, -1)
    shift(2, c, -1)

n,m = map(int,input().split())
array = []
moves = []

for i in range(n):
    array.append(list(map(int,input().split())))

pos = {}
for row in range(n):
    for column in range(m):
        pos[array[row][column]] = (row,column)

for row in range(n): #solves the first m-1 elements of each row
    solveRow(row)
    
solveLastColumn()

if array[n-1][m-2] == m*n-1:
    for _ in range(m//2-1):
        jump2Left(n*m-1)
    shift(1, n-1, -1)

print(len(moves))
for (a, b, c) in moves:
    print(str(a)+' '+str(b)+' '+str(c))