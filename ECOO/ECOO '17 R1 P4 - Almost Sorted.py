for i in range(10):
    n = int(input())
    full = []
    for j in range(n):
        full.append(input())
    min_swaps = n
    n = n - 1
    for person in full:
        names = list(full)
        names.remove(person)
        sort = list(names)
        sort.sort()
        visited = set()
        index = dict()
        for j in range(n):
            index[sort[j]] = j
        total = 0
        for j in range(n):
            if names[j] not in visited:
                start = sort[j]
                count = 0
                current = names[j]
                visited.add(start)
                while current != start:
                    count += 1
                    current = names[index[current]]
                    visited.add(current)
                total += count
        if total < min_swaps:
            min_swaps = total
    print(min_swaps)