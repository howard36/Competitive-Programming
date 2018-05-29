T = int(input())
Xs, Ys = input().split()
Xl, Yl = input().split()
Xs = int(Xs)
Ys = int(Ys)
Xl = int(Xl)
Yl = int(Yl)

if (Xs+Ys+Xl+Yl)%2 == 1:
    print("Cannot physically get there.")
else:
    steps = max(abs(Xs-Xl), abs(Ys-Yl))
    if steps > T:
        print("Cannot get there on time.")
    else:
        print("It takes "+str(steps)+" minute(s) to get to ("+str(Xl)+", "+str(Yl)+').')