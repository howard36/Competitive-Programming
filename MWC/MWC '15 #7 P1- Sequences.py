def AllZero(sequence):
    for i in range (1,N):
        if sequence[i] != 0:
            return False
    return True

N = int(input())
sequence = input().split()

for i in range (0,N):
    sequence[i] = int(sequence[i])

arithmetic = True
geometric = True
d = sequence[0] - sequence[1]
if not(AllZero(sequence)):
    if sequence[1] != 0:
        r = sequence[0]/sequence[1]
    else:
        geometric = False
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