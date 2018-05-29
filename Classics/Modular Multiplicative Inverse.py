N, M = (int(n) for n in input().split())
q = []
r = [M, N]
while r[-1] != 1:
    q.append(-(r[-2]//r[-1]))
    r.append(r[-2]%r[-1])

a = 1
b = q[-1]
q.reverse()
while len(q) > 1:
    temp_a = b
    temp_b = b*q[1]+a
    a = temp_a
    b = temp_b
    del q[0]

if b < 0:
    b += M
print(b)