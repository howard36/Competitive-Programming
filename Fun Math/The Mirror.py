n = int(input())

prime = [True]*(501)
prime[0] = False
prime[1] = False
for x in range(2, 501):
    if prime[x]:
        for i in range(2*x, 501, x):
            prime[i] = False

for _ in range(n):
    a, b = (int(n) for n in input().split())
    print(prime[a:b].count(True))