import queue
from collections import defaultdict
import sys
input = sys.stdin.readline

def BFS(graph, root, goal): 
    visited = {root}
    q = queue.Queue()
    q.put(root)
    parent = {}
    parent[root] = 'NIL'
    while not q.empty():
        current = q.get()
        if current == goal:
            path = []
            while parent[current] != 'NIL':
                path.append(current)
                current = parent[current]
            return path
        for neighbor in graph[current]:
            if neighbor not in visited:
                q.put(neighbor)
                visited.add(neighbor)
                parent[neighbor] = current
    return False

g = defaultdict(list)
while True:
    x, y = (i for i in input())
    if x == '*':
        break
    g[x].append(y)
    g[y].append(x)

path = BFS(g, 'A', 'B')
path.append('A')
roads = []
for i in range(len(path)-1):
    x = path[i]
    y = path[i+1]
    g[x].remove(y)
    g[y].remove(x)
    if BFS(g, 'A', 'B') == False:
        roads.append(x+y)
    g[x].append(y)
    g[y].append(x)

for road in roads:
    print(road)
print('There are ' + str(len(roads)) + ' disconnecting roads.')