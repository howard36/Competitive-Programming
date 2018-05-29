import sys
input = sys.stdin.readline
import math

n = int(input())
cost = 0

while n > 1:
    sqrt = math.sqrt(n)
    b = 2
    while n%b != 0 and b < sqrt+1:
        b += 1
    if b >= sqrt+1:
        b = n
    a = n//b
    n -= a
    cost += b-1
print(cost)