import sys
from collections import defaultdict
import queue
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
            count = 1
            while parent[current] != 'NIL':
                current = parent[current]
                count += 1
            return count
        for neighbor in graph[current]:
            if neighbor not in visited:
                q.put(neighbor)
                visited.add(neighbor)
                parent[neighbor] = current
    return -1
    
t = int(input())
for _ in range(t):
    r = int(input())
    c = int(input())
    temp = {}
    for y in range(r):
        row = input()
        for x in range(c):
            temp[(x,y)] = row[x]
    if temp[(c-1,r-1)] == '*':
        print(-1)
        continue
    g = defaultdict(list)
    for x in range(c):
        for y in range(r):
            if temp[(x,y)] == '+':
                if x != 0:
                    g[(x,y)].append((x-1,y))
                if x != c-1:
                    g[(x,y)].append((x+1,y))
                if y != 0:
                    g[(x,y)].append((x,y-1))
                if y != r-1:
                    g[(x,y)].append((x,y+1))
            if temp[(x,y)] == '-':
                if x != 0:
                    g[(x,y)].append((x-1,y))
                if x != c-1:
                    g[(x,y)].append((x+1,y))
            if temp[(x,y)] == '|':
                if y != 0:
                    g[(x,y)].append((x,y-1))
                if y != r-1:
                    g[(x,y)].append((x,y+1))
    print(BFS(g, (0,0), (c-1,r-1)))