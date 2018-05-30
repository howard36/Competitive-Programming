L = input().split()
x = L.count(not)
if x % 2 == 0:
    if L[-1] == 'False':
        print('False')
    if L[-1] == 'True':
        print('True')
else:
    if L[-1] == 'False':
        print('True')
    if L[-1] == 'True':
        print('False')