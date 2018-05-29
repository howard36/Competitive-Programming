import sys
imput = sys.stdin.readline

def crystal(m, x, y):
    if m == 1:
        if (x,y) in {(1,0), (2,0), (3,0), (2,1)}:
            return True
        else:
            return False
    big_x = x // (5**(m-1))
    big_y = y // (5**(m-1))
    if (big_x, big_y) in {(1,0), (2,0), (3,0), (2,1)}:
        return True
    elif (big_x, big_y) in {(1,1), (2,2), (3,1)}:
        new_x = x % (5**(m-1))
        new_y = y % (5**(m-1))
        return crystal(m-1, new_x, new_y)
    else:
        return False

t = int(input())
for _ in range(t):
    m, x, y = (int(n) for n in input().split())
    if crystal(m, x, y):
        print('crystal')
    else:
        print('empty')