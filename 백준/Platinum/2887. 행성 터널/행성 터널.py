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
        
n = int(input())
parent = [i for i in range(n+1)]

L, Lx, Ly, Lz = [],[],[],[]
for i in range(n):
    x,y,z = map(int, input().split())
    Lx.append((x,i))
    Ly.append((y,i))
    Lz.append((z,i))

Lx.sort()
Ly.sort()
Lz.sort()

for i in range(n-1):
    L.append((abs(Lx[i][0]-Lx[i+1][0]), Lx[i][1], Lx[i+1][1]))
    L.append((abs(Ly[i][0]-Ly[i+1][0]), Ly[i][1], Ly[i+1][1]))
    L.append((abs(Lz[i][0]-Lz[i+1][0]), Lz[i][1], Lz[i+1][1]))

L.sort()

cost = 0
for i in L:
    weight, a, b = i
    if find(a) != find(b):
        union(a,b)
        cost += weight

print(cost)