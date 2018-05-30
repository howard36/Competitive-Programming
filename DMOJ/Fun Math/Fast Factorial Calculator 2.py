def factorial(n):
    if n >= 2**32-5:
        return 0
    elif n==0:
        return 1
    else:
        x = n*factorial(n-1)
        y = x % (2**32-5)
        return y

N = int(input())
for i in range (N):
    n = int(input())
    print(factorial(n))