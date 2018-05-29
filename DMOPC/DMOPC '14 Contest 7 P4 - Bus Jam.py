n, m, h = (int(n) for n in input().split())
times = []
counter = 0
for _ in range(n):
    times.append(int(input()))
for i in range(n-1, 0, -1):
    while times[i]-times[i-1] > h:
        times[i-1] += m
        counter += 1
print(counter)