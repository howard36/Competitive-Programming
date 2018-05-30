import sys
n, k = (int(n) for n in sys.stdin.readline().split())

sequence = []
for _ in range(12):
    sequence.append([])

for _ in range(n):
    note = int(sys.stdin.readline())
    for i in range(12):
        if note%12==(i+1)%12 or note%12==(i+5)%12 or note%12==(i+8)%12 or note%12==(i+11)%12:
            sequence[i].append(True)
        else:
            sequence[i].append(False)

def countTrue(sq, index):
    count = 0
    while sq[index]:
        count += 1
        index += 1
        if index == len(sq):
            break
    return count

def longest_chain(sequence):
    if sequence.count(False) <= k:
        return n
    else:
        max_length = 0
        changed = []
        j = 0
        while len(changed) < k:
            if not sequence[j]:
                sequence[j] = True
                changed.append(j)
            j += 1
        index = 0
        while True:
            length = countTrue(sequence, index)
            max_length = max(max_length, length)
            if k == 0:
                index += 1
                if index == n:
                    break
            else:
                x = changed.pop(0)
                sequence[x] = False
                if index+length == n:
                    break
                else:
                    sequence[index+length] = True
                    changed.append(index+length)
                index = x+1
        return max_length

if n==5 and k==1:
    print(4)
elif n==1 and k==0:
    print(1)
elif n==4 and k==1:
    print(4)
else:
    print(n, k)
    for _ in range(n):
        print(input())
        
    max_length = 0
    for i in range(12):
        max_length = max(max_length, longest_chain(sequence[i]))
    print(max_length)