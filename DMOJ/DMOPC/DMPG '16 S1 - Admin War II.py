import sys
input = sys.stdin.readline

n = int(input())
listA = list(int(i) for i in input().split())
listB = list(int(i) for i in input().split())
listA.sort()
listB.sort()
listA.reverse()
listB.reverse()
pointer = 0
counter = 0
stop = False
for i in range(n):
    a = listA[i]
    while listB[pointer] >= a:
        pointer += 1
        if pointer == n:
            stop = True
            break
    if stop:
        break
    counter += 1
    pointer += 1
    if pointer == n:
        break
ansA = counter

pointer = 0
counter = 0
stop = False
for i in range(n):
    b = listB[i]
    while listA[pointer] >= b:
        pointer += 1
        if pointer == n:
            stop = True
            break
    if stop:
        break
    counter += 1
    pointer += 1
    if pointer == n:
        break
ansB = counter
print(ansA)
print(ansB)