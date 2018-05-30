import sys
input = sys.stdin.readline

n = int(input())
for _ in range(n):
    s = input()
    substrings = set()
    count = 0
    for end in range(len(s)):
        for start in range(end+1):
            x = s[start:end]
            if x not in substrings:
                substrings.add(x)
                count += 1
    print(count)