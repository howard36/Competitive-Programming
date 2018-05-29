limit = int(input())
speed = int(input())
x = speed - limit
if x < 1:
    print('Congratulations, you are within the speed limit!')
elif x < 21:
    print('You are speeding and your fine is $100.')
elif x < 31:
    print('You are speeding and your fine is $270.')
else:
    print('You are speeding and your fine is $500.')