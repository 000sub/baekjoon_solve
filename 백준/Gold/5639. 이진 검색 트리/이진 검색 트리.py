import sys
sys.setrecursionlimit(10**5)
input = sys.stdin.readline

L = []
while True:
    try:
        L.append(int(input()))
    except:
        break

def order(s, e):

    if s>e:
        return

    mid = e+1
    for i in range(s+1, e+1):
        if L[s]<L[i]:
            mid = i
            break

    order(s+1, mid-1)
    order(mid, e)
    print(L[s])

order(0,len(L)-1)