V = int(input());
string = input();
A = string.count('A')
B = string.count('B')

if A > B:
    print('A')
elif A < B:
    print('B')
else:
    print('Tie')