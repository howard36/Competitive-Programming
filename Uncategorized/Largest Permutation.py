n, k = (int(n) for n in input().split())
p = []
for number in input().split():
    p.append(int(number))

changes = 0
current = n
while changes < k:
    if p[n-current] == current:
        current -= 1
    else:
        index = p.index(current)
        p[index] = p[n-current]
        p[n-current] = current
        changes += 1
        current -= 1
    if current == 1:
        break

for number in p:
    print(number, end=' ')