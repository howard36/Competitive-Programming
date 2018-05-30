N, X = input().split()
N = int(N)
X = int(X)
age = []
purpose = []
count = 0
for i in range (0,N):
    a, b = input().split()
    age.append(int(a))
    purpose.append(int(b))

for i in range (0,N-1):
    if (age[i]-age[i+1]) * (purpose[i]-purpose[i+1]) > 0:
        s = age[i] + age[i+1]
        age[i] = s - age[i]
        age[i+1] = s - age[i+1]

for i in range (0,N):
    if age[i] > X:
        if purpose[i]==0:
            count += 1
    else:
        if purpose[i]==1:
            count += 1

print(count)