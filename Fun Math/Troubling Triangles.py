import math

def abs(x):
    if x < 0:
        return -x
    else:
        return x

def dist(x1, y1, x2, y2):
    return math.sqrt((x1-x2)**2+(y1-y2)**2)

n = int(input())
for _ in range(n):
    x1, y1, x2, y2, x3, y3 = (float(n) for n in input().split())
    A = float(abs((x1*y2+x2*y3+x3*y1-y1*x2-y2*x3-y3*x1)/2))
    P = dist(x1, y1, x2, y2) + dist(x2, y2, x3, y3) + dist(x3, y3, x1, y1)
    print(str(A), str(P))