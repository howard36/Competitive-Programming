import sys
input = sys.stdin.readline

n,k = (int(i) for i in input().split())

if k>3:
    print(0)
else:
    jval = [1]*(n+1)
    jval[0]=0
    jval[1]=0
    for i in range(2,n//2+2):
        if jval[i]:
            for j in range(2*i,n+1,i):
                jval[j]=0
    for i in range(2,n-1):
        if jval[i]==1:
            if jval[i+2]==0:
                jval[i+2]=2
    
    
    for i in range(4,n+1,2):
        jval[i]=2
    for i in range(5,n+1,2):
        if jval[i]==0:
            jval[i]=3
    
    print(jval.count(k))