import math

# n, h = (int(i) for i in input().split())
def solve(n, h):
    if n <= h*(h+1)/2:
        k = int(math.sqrt(2*n))
        if n <= k*(k+1)/2: # for some reason, python thinks that 999999997351043581 <= 1414213560*1414213561/2
            print(k)
        else:
            print(k+1)
    else:
        x = n + h*(h-1)/2
        k = int(math.ceil(math.sqrt(x)))
        if x <= k*k-k:
            print(2*k-h-1)
        else:
            print(2*k-h)

solve(n, h)
