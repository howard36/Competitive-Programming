import sys
input = sys.stdin.readline
from collections import defaultdict
import queue

def BFS(start, end):
    q = queue.Queue()
    q.put(start)
    visited = {start}
    while not(q.empty()):
        current = q.get()
        for neighbor in g[current]:
            if neighbor == end:
                return True
            if neighbor not in g or neighbor not in visited:
                visited.add(neighbor)
                q.put(neighbor)
    return False

g = defaultdict(set)
n, m = (int(i) for i in input().split())
for _ in range(m):
    taller, shorter = (int(i) for i in input().split())
    g[taller].add(shorter)
p, q = (int(i) for i in input().split())
if BFS(p, q):
    print('yes')
elif BFS(q, p):
    print('no')
else:
    print('unknown')