import sys
input = sys.stdin.readline

n = int(input())

L = [[] for _ in range(n)]

for i in range(n):
    L[i] = list(map(int,input().rstrip()))

def div_con(li, N):
    one = False
    zero = False
    for i in range(N):
        for j in range(N):
            if li[i][j] == 0:
                zero = True
            if li[i][j] == 1:
                one = True

    if one and zero:
        li1 = [li[i][:N//2] for i in range(0,N//2)]
        li2 = [li[i][N//2:] for i in range(0,N//2)]
        li3 = [li[i][:N//2] for i in range(N//2, N)]
        li4 = [li[i][N//2:] for i in range(N//2, N)]

        return '('+div_con(li1,N//2)+div_con(li2,N//2)+div_con(li3,N//2)+div_con(li4,N//2)+')'

    else:
        if one:
            return '1'
        else:
            return '0'

ans = div_con(L, n)
print(ans)
