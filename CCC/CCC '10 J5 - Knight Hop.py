from collections import defaultdict
import queue

g = defaultdict(list)
for x in range(1, 9):
    for y in range(1, 9):
        if x < 8 and y < 7:
            g[(x, y)].append((x+1, y+2))
            g[(x+1, y+2)].append((x, y))
        if x < 7 and y < 8:
            g[(x, y)].append((x+2, y+1))
            g[(x+2, y+1)].append((x, y))
        if x > 1 and y < 7:
            g[(x, y)].append((x-1, y+2))
            g[(x-1, y+2)].append((x, y))
        if x > 2 and y < 8:
            g[(x, y)].append((x-2, y+1))
            g[(x-2, y+1)].append((x, y))

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
                
x1, y1 = (int(n) for n in input().split())
x2, y2 = (int(n) for n in input().split())
print(len(BFS(g, (x1, y1), (x2, y2))))