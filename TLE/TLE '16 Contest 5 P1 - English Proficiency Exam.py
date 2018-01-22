text = input().split()
def readable(word):
    if len(word) == 1:
        if word in 'aeiou':
            return True
        else:
            return False
    else:
        vowels = word.count('a') + word.count('e') + word.count('i') + word.count('o') + word.count('u')
        consonants = len(word) - vowels
        if -1 <= vowels - consonants <= 1:
            return True
        else:
            return False

readableText = True
for word in text:
    if not readable(word):
        readableText = False

if readableText:
    print('readable')
else:
    print('not readable')