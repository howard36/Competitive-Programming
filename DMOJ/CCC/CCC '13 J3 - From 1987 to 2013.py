year = int(input())
TwoDigitsAreEqual = True
while TwoDigitsAreEqual:
    year += 1
    TwoDigitsAreEqual = False
    for x in range(len(str(year))-1):
        for y in range(x+1, len(str(year))):
            if str(year)[x] == str(year)[y]:
                TwoDigitsAreEqual = True
print(year)