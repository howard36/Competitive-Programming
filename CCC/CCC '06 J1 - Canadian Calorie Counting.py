a = int(input())
b = int(input())
c = int(input())
d = int(input())
S = 0

if a == 1:
    S += 461
elif a == 2:
    S += 431
elif a == 3:
    S += 420


if b == 1:
    S += 100
elif b == 2:
    S += 57
elif b == 3:
    S += 70
    
if c == 1:
    S += 130
elif c == 2:
    S += 160
elif c == 3:
    S += 118

if d == 1:
    S += 167
elif d == 2:
    S += 266
elif d == 3:
    S += 75
    
print('Your total Calorie count is ' + str(S) + '.')