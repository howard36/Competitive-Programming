first=input()
second=input()
output='A'
for letter in range (ord('a'),ord('z')+1):
    if second.count(chr(letter)) > first.count(chr(letter)):
        output='N'
print(output)