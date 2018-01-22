daytime = int(input())
evening = int(input())
weekend = int(input())
A = (max(0, daytime - 100)) * 25 + evening * 15 + weekend * 20
B = (max(0, daytime - 250)) * 45 + evening * 35 + weekend * 25

print('Plan A costs ' + str(int(A)/100))
print('Plan B costs ' + str(int(B)/100))
if A < B:
    print('Plan A is cheapest.')
if A > B:
    print('Plan B is cheapest.')
if A == B:
    print('Plan A and B are the same price.')