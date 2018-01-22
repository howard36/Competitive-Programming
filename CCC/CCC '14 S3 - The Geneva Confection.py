import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n = int(input())
    mountain = []
    branch = []
    possible = True
    for _ in range(n):
        mountain.append(int(input()))
    for candy in range(1, n+1):
        if candy in mountain:
            for i in range(len(mountain) - mountain.index(candy) - 1):
                branch.append(mountain.pop())
            del mountain[-1]
        elif len(branch)>0:
            if branch[-1] == candy:
                del branch[-1]
            else:
                possible = False
                break
        else:
            possible = False
            break
    if possible:
        print('Y')
    else:
        print('N')