n = int(input())
for _ in range(n):
    s = input()
    t = input()
    while len(t) > len(s):
        if t[-1] == 'A':
            t = t[:-1]
        else:
            t = t[-2::-1]
    if s == t:
        print('YES')
    else:
        print('NO')