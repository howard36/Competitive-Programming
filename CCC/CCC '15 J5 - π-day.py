import math

memo = {}
def pie(pies, people, max_pie):
    if (pies, people, max_pie) in memo:
        return memo[(pies, people, max_pie)]
    if people == pies or max_pie == 1:
        memo[(pies, people, max_pie)] = 1
        return 1
    else:
        counter = 0
        minimum = math.ceil(pies/people)
        maximum = min(pies-people+1, max_pie)
        for last_person in range(minimum, maximum+1):
            counter += pie(pies-last_person, people-1, last_person)
        memo[(pies, people, max_pie)] = counter
        return counter
n = int(input())
k = int(input())
print(pie(n, k, n))