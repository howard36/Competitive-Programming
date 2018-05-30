t = int(input())
s = int(input())
h = int(input())
for _ in range(t):
    print('*' + ' '*s + '*' + ' '*s + '*')
print('*'*(2*s+3))
for _ in range(h):
    print(' '*(s+1) + '*')