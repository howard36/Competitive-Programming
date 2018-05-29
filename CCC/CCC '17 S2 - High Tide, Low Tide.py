import sys
input = sys.stdin.readline

n = int(input())
waves = []
for x in input().split():
    waves.append(int(x))
waves.sort()
if n%2 == 0:
    mid = n//2
else:
    mid = (n+1)//2
order = []
for i in range(n):
    if i%2 == 0: #low
        order.append(waves[mid-1-i//2])
    else:
        order.append(waves[mid+i//2])
for m in order:
    print(m, end=' ')