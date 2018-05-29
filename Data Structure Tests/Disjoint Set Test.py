n, m = (int(n) for n in input().split())
#connectivity = {x:{x} for x in range(1, n+1)}
#c = {x:x for x in range(1, n+1)}
DS = {frozenset([x]) for x in range(1, n+1)}
EdgesInTree = []
connected = False

def find(x):
    for subset in DS:
        if x in subset:
            return subset

def union(set1, set2):
    DS.add(set1 | set2)
    DS.remove(set1)
    DS.remove(set2)

for edge in range(1, m+1):
    a, b = (int(n) for n in input().split())
    set_a = find(a)
    set_b = find(b)
    if set_a != set_b:
        union(set_a, set_b)
        EdgesInTree.append(edge)
    '''
    if len(DS) == 1:
        connected = True
        break
        '''

if len(DS) == 1:
    for edge in EdgesInTree:
        print(edge)
else:
    print("Disconnected Graph")