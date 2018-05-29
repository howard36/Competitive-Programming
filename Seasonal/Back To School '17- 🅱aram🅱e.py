words = list(input().split())
for i in range (1,len(words)):
    if ord(words[i][0]) < ord('a'):
        words[i-1] += '.'
words[-1] += '.'
for word in words:
    print(word, end = ' ')