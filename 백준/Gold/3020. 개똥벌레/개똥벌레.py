import sys

n, h = map(int, sys.stdin.readline().split())
top = [0] *h
down = [0] * h

for i in range(n):
    temp = int(sys.stdin.readline())

    if i%2==0:
        down[temp-1]+=1
    else:
        top[h-temp]+=1

for i in range(h-1):
    top[i+1] += top[i]

for i in range(h-1,0,-1):
    down[i-1] += down[i]

L = []
for i in range(h):
    L.append(down[i]+top[i])

minnum = min(L)

cnt = L.count(minnum)

print(minnum, cnt)
