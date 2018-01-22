def intersections(n):
    if n == 3:
        return 0
    else:
        counter = intersections(n-1)
        for i in range(n-1):
            counter += i*(n-i-2)
        return counter
n = int(input())
print(intersections(n))