a = 0
b = 1
n = int(input())
n = n % 200000016

for _ in range(2, n+1):
    nextTerm = (a+b) % (10**9+7)
    a = b
    b = nextTerm
print(b)