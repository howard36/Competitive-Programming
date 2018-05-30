import math

k = int(input())

def maxTriangularNumber(n):
    x = math.floor(math.sqrt(2*n))
    if x**2+x <= 2*n:
        return x+1
    else:
        return x

loopLength = []
while k > 0:
    m = maxTriangularNumber(k)
    loopLength.append(m)
    k -= (m**2-m)//2

print(sum(loopLength)+1, sum(loopLength)+len(loopLength))
counter = 2
for i in range(len(loopLength)):
    print(1,counter)
    for j in range(loopLength[i]-1):
        print(counter+j, counter+j+1)
    print(counter+loopLength[i]-1, counter)
    counter += loopLength[i]