import sys
input = sys.stdin.readline

n = int(input())
L = []
for _ in range(n):
    L.append(list(map(int, input().split())))

b, w = 0,0

def div(x,y,k):
    global b,w
    blue, white = False, False
    for i in range(y,y+k):
        for j in range(x,x+k):
            if blue and white:
                break
            if L[i][j] == 1:
                blue = True
            if L[i][j] == 0:
                white = True

    if blue and not white:
        b+=1
        return
    elif not blue and white:
        w+=1
        return
    else:
        div(x,y,k//2)
        div(x+k//2,y,k//2)
        div(x,y+k//2,k//2)
        div(x+k//2,y+k//2,k//2)
        return

div(0,0,n)
print(w)
print(b)
