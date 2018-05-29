N = int(input())
sequence = input().split()

for i in range (0,N):
    sequence[i] = int(sequence[i])

arithmetic = True
geometric = True
d = sequence[0] - sequence[1]
if sequence[1] == 0:
    geometric = False
else:
    r = sequence[0]/sequence[1]
for i in range (1,N-1):
    if sequence[i] - sequence[i+1] != d:
        arithmetic = False
    if sequence[i+1] == 0:
        geometric = False
    else:
        if sequence[i]/sequence[i+1] != r:
            geometric = False

if arithmetic:
    if geometric:
        print('both')
    else:
        print('arithmetic')
else:
    if geometric:
        print('geometric')
    else:
        print('random')