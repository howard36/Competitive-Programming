def nextPrime(x):
    for i in range(x, 10000000000):
        for j in range(2, i):
            if j*j>i:
                return i
            if i%j==0:
                break
               
x = int(input())
print(nextPrime(x))