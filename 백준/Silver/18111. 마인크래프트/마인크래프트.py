import sys
L=[]

def get_cost(target):
    cost = 0
    block = 0
    for i in L:
        if i > target:
            cost+= (i-target)*2
            block-=(i-target)
        else:
            cost += target-i
            block += target-i

    return cost, block
n,m,b = map(int, sys.stdin.readline().split())
for _ in range(n):
    a = list(map(int, sys.stdin.readline().split()))
    for i in a:
        L.append(i)


cur_cost = float('inf')
height = 0
for i in range(0, max(L)+1):
    c1, b1 = get_cost(i)

    if b1>b: continue
    else:
        if c1 <= cur_cost:
            cur_cost = c1
            height = i



print(cur_cost, height)
