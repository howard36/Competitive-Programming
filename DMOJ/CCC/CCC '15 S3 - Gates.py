import sys
input = sys.stdin.readline

g = int(input())
p = int(input())
available = {i for i in range(1,g+1)}
count = 0
stop = False

for index in range(p):
    max_gate = int(input())
    stop = True
    for gate in range(max_gate, 0, -1):
        if gate in available:
            available.remove(gate)
            count += 1
            stop = False
            break
    if stop:
        break
    
print(count)