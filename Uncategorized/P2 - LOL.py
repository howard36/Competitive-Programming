def abs(x):
    if x < 0:
        return -x
    else:
        return x

n = int(input())
xlist = []
ylist = []
for _ in range(n):
    x, y = (int(n) for n in input().split())
    xlist.append(x)
    ylist.append(y)
    
xlist.sort()
ylist.sort()
xdiff = abs(xlist[0] - xlist[-1])
ydiff = abs(ylist[0] - ylist[-1])
print(xdiff*ydiff)