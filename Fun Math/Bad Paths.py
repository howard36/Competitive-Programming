import sys

mod = 10**9+7
inputList = list(map(int,sys.stdin.read().split('\n')[1:]))
maximum = max(i for i in inputList)

g = [0]*(maximum+1)
for i in range(1,maximum+1):
    g[i]=i*(g[i-1]+1)%mod
for i in inputList:
    print(((g[i]-i*i)*(mod+1)//2)%mod)