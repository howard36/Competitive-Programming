N = int(input())
for _ in range(N):
    A, B, P = input().split()
    A = int(A)
    B = int(B)
    P = int(P)
    if A * B == P:
        print('POSSIBLE DOUBLE SIGMA')
    else:
        print('16 BIT S/W ONLY')