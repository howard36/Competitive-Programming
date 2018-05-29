import sys
input = sys.stdin.readline
mod = 10**9+7

def count(n,m):
    counter = 0
    for i in range(1,min(n,m)+1):
        counter += i*(n-i)*(m-i)
        counter %= mod
    return counter

T = int(input())
for i in range(1,T+1):
    r,c = map(int, input().split())
    print("Case #"+str(i)+": "+str(count(r,c)))