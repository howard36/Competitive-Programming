import heapq
from collections import defaultdict
g = defaultdict(dict)

N, M = (int(n) for n in input().split())

for _ in range(M):
    u, v, w = (int(i) for i in input().split())
    if v in g[u]:
        g[u][v] = min(g[u][v],w)
        g[v][u] = g[u][v]
    else:
        g[u][v] = w
        g[v][u] = w

distance = [0, 0]
pq = []

heapq.heappush(pq, (0,1))
for i in range (2,N+1):
    distance.append(float("inf"))
    heapq.heappush(pq, (float("inf"), i))
   

while pq:
    d, v = heapq.heappop(pq)
    for neighbor in g[v]:
        weight = g[v][neighbor]
        tempdistance = distance[v] + weight
        if tempdistance < distance[neighbor]:
            distance[neighbor] = tempdistance
            heapq.heappush(pq, (tempdistance, neighbor))
    
for node in range(1, N+1):
    if distance[node] == float("inf"):
        print(-1)
    else:
        print(distance[node])