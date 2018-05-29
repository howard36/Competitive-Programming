n = int(input())
heights = list(int(i) for i in input().split())

heights.sort()
heights.reverse()

maxVolume = (heights[1]-1)*(n-2)

possible = [0]*(maxVolume+1)
possible[0] = 1
for i in range(1, n):
    for j in range(maxVolume+1):
        if possible[maxVolume-j]:
            for k in range(1,i):
                if maxVolume-j+heights[k]-heights[i] <= maxVolume:
                    possible[maxVolume-j+heights[k]-heights[i]]=1
for i in range(maxVolume+1):
    if possible[i]:
        print(i, end=' ')