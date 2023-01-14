import random

b, d, a = [int(i) for i in input().split()]

def euclid(a, b):
    if b == 0: return 1, 0
    c, d = euclid(b, a%b)
    return d, c - (a // b) * d

def inv(a, b):
    c, d = euclid(a,b)
    assert(c*a + d*b == 1)
    return (c+b) % b

def maxZeros(b, a):
    e2, e5 = 0, 0
    while b % 2 == 0:
        e2 += 1
        b //= 2
    while b % 5 == 0:
        e5 += 1
        b //= 5
    b *= 2**e2 * 5**e5
    lo, hi = 0, 10004
    while lo < hi:
        k = (lo + hi + 1) // 2
        n = 2**max(k-e2,0) * 5**max(k-e5,0)
        if n*b > a:
            hi = k-1
        else:
            lo = k
    return lo

def solve(b, d, a):
    if b % 10 == 0:
        if d % 10 != 0:
            return 0
        return maxZeros(b, a)
    elif d == 0:
        return maxZeros(b, a)
    elif b % 5 == 0:
        e = 0
        while b % 5 == 0:
            e += 1
            b //= 5
        b *= 5**e
        if d % (5**e) != 0:
            ans = 0
            for n in range(1, 1003):
                if n*b > a:
                    break
                if (n*b - d) % 10 == 0:
                    ans = max(ans, 1)
                if (n*b - d*11) % 100 == 0:
                    ans = max(ans, 2)
                if (n*b - d*111) % 1000 == 0:
                    ans = max(ans, 3)
            return ans
        lo, hi = 0, 10004
        while lo < hi:
            k = (lo + hi + 1) // 2
            mod = 10**k // 5**min(e,k)
            dd = d // 5**min(e,k)
            bb = b // 5**min(e,k)
            n = (inv(bb, mod) * dd * (10**k-1) // 9) % mod
            if n == 0:
                n += mod
            if n*b > a:
                hi = k-1
            else:
                lo = k
        return lo
    elif b % 2 == 0:
        e = 0
        while b % 2 == 0:
            e += 1
            b //= 2
        b *= 2**e
        if d % (2**e) != 0:
            ans = 0
            for n in range(1, 1003):
                if n*b > a:
                    break
                if (n*b - d) % 10 == 0:
                    ans = max(ans, 1)
                if (n*b - d*11) % 100 == 0:
                    ans = max(ans, 2)
                if (n*b - d*111) % 1000 == 0:
                    ans = max(ans, 3)
            return ans
        lo, hi = 0, 10004
        while lo < hi:
            k = (lo + hi + 1) // 2
            mod = 10**k // 2**min(e,k)
            dd = d // 2**min(e,k)
            bb = b // 2**min(e,k)
            n = (inv(bb, mod) * dd * (10**k-1) // 9) % mod
            if n == 0:
                n += mod
            if n*b > a:
                hi = k-1
            else:
                lo = k
        return lo
    else:
        lo, hi = 0, 10004
        while lo < hi:
            k = (lo + hi + 1) // 2
            mod = 10**k
            n = (inv(b, mod) * d * (mod-1) // 9) % mod
            if n == 0:
                n += mod
            if n*b > a:
                hi = k-1
            else:
                lo = k
        return lo

def solve2(b, d, a):
    ans = 0
    for n in range(1, 100000000000):
        if n*b > a:
            return ans
        for k in range(1, 10):
            if (n*b - d * (10**k-1) // 9) % (10**k) == 0:
                ans = max(ans, k)
            else:
                break

print(solve(b,d,a))

'''
print(solve2(b,d,a))

for i in range(10000000000):
    b = 1 + random.randrange(1000)
    d = random.randrange(10)
    a = b + random.randrange(100000)
    if solve(b,d,a) != solve2(b,d,a):
        print("Bad!", b, d, a, solve(b,d,a), solve2(b,d,a))
    if i % 1000 == 0:
        print(i)
'''
    

