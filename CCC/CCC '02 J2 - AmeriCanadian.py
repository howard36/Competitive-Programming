while True:
    word = input()
    if word == 'quit!':
        break
    if not(word.endswith('or')):
        print(word)
    else:
        if len(word) <= 3 or word.endswith('aor') or word.endswith('eor') or word.endswith('ior') or word.endswith('oor') or word.endswith('uor') or word.endswith('yor'):
            print(word)
        else:
            newword = word[0:-2] + 'our'
            print(newword)