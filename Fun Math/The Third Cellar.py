n = int(input())

prime = [True]*(1000000)
prime[1] = False
for x in range(2, 1000000):
    if prime[x]:
        for i in range(2*x, 1000000, x):
            prime[i] = False

for _ in range(n):
    a, b = (int(n) for n in input().split())
    print(prime[a:b].count(True))