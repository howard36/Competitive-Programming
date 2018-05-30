def binary(n):
    if n == 0:
        return [0]
    elif n == 1:
        return [1]
    elif n % 2 == 1:
        digits = binary(int((n-1)/2))
        digits.append(1)
        return digits
    else:
        digits = binary(int(n/2))
        digits.append(0)
        return digits

def format(n):
    digits = binary(n)
    x = len(digits)
    y = -((-x)//4)
    for _ in range (0,4*y-x):
        digits.insert(0, 0)
    for i in range (4, 5*y-1, 5):
        digits.insert(i, ' ')
    return digits

N = int(input())
base10 = []
for _ in range(0,N):
    base10.append(int(input()))

for i in range(0,N):
    n = base10[i]
    for j in format(n):
        print(j, end='')
    print()