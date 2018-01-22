import sys
input = sys.stdin.readline
import math

Q = int(input())
for _ in range(Q):
    x, N, F_or_D = (float(i) for i in input().split())
    if x == 1:
        F = F_or_D
        D = math.ceil(N**(1/F)-1)
        if N <= D**F: print(D-1)
        else: print(D)
    else:
        D = F_or_D
        F = math.ceil(math.log(N, D+1))
        if N <= (D+1)**(F-1): print(F-1)
        else: print(F)