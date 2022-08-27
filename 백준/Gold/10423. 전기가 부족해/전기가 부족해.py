import sys
input = sys.stdin.readline

def find(i):
    if parent[i] != i:
        parent[i] = find(parent[i])

    return parent[i]

def union(a,b):
    a = find(a)
    b = find(b)

    if a>b:
        parent[a] = b
    else:
        parent[b] = a
n,m,k = map(int,input().split())
elec = list(map(int, input().split()))

L=[]
parent = [i for i in range(n+1)]
for _ in range(m):
    u,v,w = map(int, input().split())
    L.append((w,u,v))

tmp = min(elec)
for e in elec:
    union(e, tmp)

L.sort()

cost = 0
for i in range(m):
    w,u,v = L[i]
    if find(u) != find(v):
        union(u,v)
        cost += w

print(cost)
