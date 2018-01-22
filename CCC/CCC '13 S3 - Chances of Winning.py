import sys
input = sys.stdin.readline
import copy

t = int(input())
games = int(input())
points = {}
for i in range(1,5):
    g = {}
    for j in range(1,5):
        if i != j:
            g[j] = -1
    points[i] = g
for _ in range(games):
    a, b, s_a, s_b = (int(n) for n in input().split())
    if s_a > s_b:
        points[a][b] = 3
        points[b][a] = 0
    elif s_b > s_a:
        points[a][b] = 0
        points[b][a] = 3
    else:
        points[a][b] = 1
        points[b][a] = 1

def possibilities(p):
    count = 0
    for i in range(1,5):
        for j in p[i]:
            if p[i][j] == -1:
                temp1 = copy.deepcopy(p)
                temp1[i][j] = 3
                temp1[j][i] = 0
                count += possibilities(temp1)
                temp2 = copy.deepcopy(p)
                temp2[i][j] = 0
                temp2[j][i] = 3
                count += possibilities(temp2)
                temp3 = copy.deepcopy(p)
                temp3[i][j] = 1
                temp3[j][i] = 1
                count += possibilities(temp3)
                return count
    total = [0,0,0,0]
    for i in range(1,5):
        for j in p[i]:
            total[i-1] += p[i][j]
    if total[(t-1)%4] > total[t%4] and total[(t-1)%4] > total[(t+1)%4] and total[(t-1)%4] > total[(t+2)%4]:
        return 1
    else:
        return 0

print(possibilities(points))