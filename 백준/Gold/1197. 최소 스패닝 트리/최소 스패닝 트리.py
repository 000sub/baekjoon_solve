import sys
input = sys.stdin.readline
        
v, e = map(int, input().split())
parent = [i for i in range(v+1)]
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
    

L = []

for _ in range(e):
    a,b,c = map(int, input().split())
    L.append((c,a,b))

L.sort()

cost = 0

for i in range(len(L)):
    c,a,b = L[i]
    if find(a) != find(b):
        union(a,b)
        cost += c

print(cost)
