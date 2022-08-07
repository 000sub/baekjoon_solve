from collections import deque

L = []

N= int(input())

for i in range(N):
    L.append(input())


for i in range(N):
    vps = True
    stack = deque()
    for j in L[i]:
        if j=='(':
            stack.append(j)
        if j==')':
            if len(stack)==0:
                vps = False
            else:
                stack.pop()

    if vps==True and len(stack)==0:
        print("YES")
    else:
        print("NO")