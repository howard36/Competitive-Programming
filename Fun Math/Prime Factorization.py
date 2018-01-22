import math

n = int(input())

def factorize(n):
    factors = []
    d = 2
    while d*d <= n:
        while n % d == 0:
            factors.append(d)
            n = n//d
        d += 1
    if n > 1:
        factors.append(n)
    return factors

for _ in range(n):
    m = int(input())
    for i in factorize(m):
        print(i, end = ' ')
    print()