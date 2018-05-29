import sys
input = sys.stdin.readline

def check():
    for i in range(n-1,0,-1):
        if l1[i] == l2[i]:
            return i+1
    if l1[0] == l2[0]:
        return 1
    return 0

n = int(input())
l1 = []
l2 = []
for x in input().split():
    l1.append(int(x))
for x in input().split():
    l2.append(int(x))
for i in range(1,n):
    l1[i] += l1[i-1]
    l2[i] += l2[i-1]
print(check())