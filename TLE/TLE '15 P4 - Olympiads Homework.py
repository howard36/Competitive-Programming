mod1 = 7699
mod2 = 129887
ord1 = 2566
ord2 = 64943
inv = 191565459 #inverse of mod2-mod1 modulo 10**9+13
rem1 = [1]*ord1
rem2 = [1]*ord2
for i in range(1,ord1):
    rem1[i] = rem1[i-1]*2%mod1
for i in range(1,ord2):
    rem2[i] = rem2[i-1]*2%mod2

n = int(input())
if n==1:
    ans = 1
else:
    x = n%8
    if x in {0, 1,7}:
        r1 = rem1[(n-2)%ord1] + rem1[(n//2-1)%ord1]
        r2 = rem2[(n-2)%ord2] + rem2[(n//2-1)%ord2]
    elif x in {2,6}:
        r1 = rem1[(n-2)%ord1]
        r2 = rem2[(n-2)%ord2]
    else:
        r1 = rem1[(n-2)%ord1] - rem1[(n//2-1)%ord1]
        r2 = rem2[(n-2)%ord2] - rem2[(n//2-1)%ord2]
    ans = (r1*mod2-r2*mod1)*inv%(10**9+13)
print(ans)