import sys
input = sys.stdin.readline

mod = 10**9+7

n = int(input())
a = []
for i in input().split():
    a.append(int(i))
m = int(input())
m %= mod

b = [0]*(n-1)
b.append(1)
for i in range(1,n):
    b.append(b[-1]*(i+m-1)//i)
for i in range(n-1,2*n-1):
    b[i] %= mod

for i in range(n):
    count = 0
    for j in range(n):
        count = (count + a[j]*b[n-1+i-j])%mod
    print(count,end=' ')