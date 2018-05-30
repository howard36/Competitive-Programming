import sys

n = int(sys.stdin.readline())
count = {}

for _ in range(n):
    i = int(sys.stdin.readline())
    if i in count:
        count[i] = not(count[i])
    else:
        count[i] = True

for number in count:
    if count[number]:
        print(number)