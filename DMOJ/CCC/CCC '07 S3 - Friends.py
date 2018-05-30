import sys
input = sys.stdin.readline

def check(start, end):
    current = g[start]
    distance = 0
    while current != start:
        if current == end:
            return distance
        else:
            current = g[current]
            distance += 1
    return -1
            
g = {}
n = int(input())
for _ in range(n):
    a, b = (int(i) for i in input().split())
    g[a] = b
while True:
    a, b = (int(i) for i in input().split())
    if a == 0:
        break
    result = check(a, b)
    if result == -1:
        print('No')
    else:
        print('Yes '+str(result))