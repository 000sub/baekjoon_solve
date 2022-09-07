import sys
input = sys.stdin.readline

n = int(input())
L = list(map(int, input().split()))

s, e = 0, n-1
a1, a2 = 0, n-1
rst = abs(L[s]+L[e])

while s<e:
    tmp = L[s]+L[e]

    if abs(tmp)<rst:
        rst=abs(tmp)
        a1, a2 = s, e

    if tmp == 0:
        break
    elif tmp<0:
        s+=1
    else:
        e-=1

    

print(L[a1], L[a2])