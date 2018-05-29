N = int(input())
L = []
for _ in range(N):
    L.append(int(input()))
L.sort()
for i in range(N):
    print(L[i])