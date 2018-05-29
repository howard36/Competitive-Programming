def d(X, Y, n):
    maxdistance = 0
    j = 0
    for i in range(n):
        while Y[j] >= X[i]:
            if j-i > maxdistance:
                maxdistance = j-i
            if j == n-1:
                break
            j += 1
        j -= 1
        if j == n-1:
            break
    return maxdistance

m = int(input())
for _ in range(m):
    n = int(input())
    X = []
    Y = []
    for i in input().split():
        X.append(int(i))
    for i in input().split():
        Y.append(int(i))
    print('The maximum distance is '+str(d(X, Y, n)))