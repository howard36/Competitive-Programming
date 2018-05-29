import sys
input = sys.stdin.readline
import math

def closeToInt(x):
    x %= 1
    return (x<0.00000001 or x>0.99999999)

Q = int(input())
for _ in range(Q):
    x, N, F_or_D = (float(i) for i in input().split())
    if Q>10:
        print(x,N,F_or_D)
    if x == 1:
        ans = N**(1/F_or_D)-1
    else:
        ans = math.log(N, F_or_D+1)
    if closeToInt(ans):
        print(int(ans))
    else:
        print(int(math.ceil(ans)))