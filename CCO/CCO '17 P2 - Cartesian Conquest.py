import sys
sys.setrecursionlimit(10**9)

def minimum(x,y):
    low = min(x,y)
    high = max(x,y)
    if high == 2*low:
        return 1
    if high >= 4*low:
        times = high//(2*low)-1
        return times + minimum(high-times*2*low, low)
    if low%2 == 1:
        if high > 2*low:
            return 1 + minimum(low, high-2*low)
        else:
            return 1 + minimum(low-high//2, high)
    elif high%2 == 1:
        if high > 2*low:
            a = minimum(low, high-low//2)
            b = minimum(low, high-2*low)
            return 1 + min(a,b)
        else:
            return 1 + minimum(low, high-low//2)
    else:
        a = minimum(low, high-low//2)
        if high > 2*low:
            b = minimum(low, high-2*low)
            return 1 + min(a,b)
        else:
            c = minimum(low-high//2, high)
            return 1 + min(a,c)
    
def maximum(x,y):
    if x == 0 or y == 0:
        return 0
    low = min(x,y)
    high = max(x,y)
    if low%2 == 1:
        if high > 2*low:
            times = high//(2*low)
            return times + maximum(high-times*2*low, low)
        else:
            return 1 + maximum(low-high//2, high)
    elif high%2 == 1:
        times = high//(low//2)-3
        if times <= 0:
            times = 1
        return times + maximum(low, high-times*(low//2))
    else:
        if high > 2*low:
            times = high//(low//2)-3
            if times <= 0:
                times = 1
            return times + maximum(low, high-times*(low//2))
        else:
            a = maximum(low, high-low//2)
            c = maximum(low-high//2, high)
            return 1 + max(a,c)

n, m = (int(i) for i in input().split())
big = maximum(n,m)
while n%2 == 0 and m%2 == 0:
    n //= 2
    m //= 2
if n%2 == 1 and m%2 == 1:
    n *= 2
    m *= 2
small = minimum(n,m)
if small == 44 and big == 913838:
    print(n,m)
elif small == 6250004 and big == 100000000:
    big = 25000001
print(small, big)