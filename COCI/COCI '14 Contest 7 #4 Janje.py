n,k = map(int, input().split())

if k==2:
    if n in {1,3,4}: ans = 2
    else: ans = 0
else:
    kC3 = k*(k-1)*(k-2)//6

    if n==1:    ans = kC3*(3*2**19-6)+k*(k-1)
    elif n==2:  ans = kC3*3*2**5
    elif n==3:  ans = kC3*(3*2**3-6)+k*(k-1)
    elif n==4:  ans = kC3*(3*2**13-6)+k*(k-1)
    elif n==5:  ans = kC3*3*2**2
    elif n==6:  ans = kC3*3*2
    elif n==7:  ans = kC3*3*2**5
    else:       ans = kC3*(2**30+2-6)+k*(k-1)

print(ans)