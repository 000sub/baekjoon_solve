import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

n, m = map(int, input().split())

L = [i for i in range(n+1)]

def find_parent(i):
    if L[i] == i:
        return i
    L[i] = find_parent(L[i])

    return L[i]

def union(a,b):
    a = find_parent(a)
    b = find_parent(b)
    if a<b:
        L[b] = a
    else:
        L[a] = b

for _ in range(m):
    op, a, b = map(int, input().split())

    if op == 1:
        x = find_parent(a)
        y = find_parent(b)
        if x != y:
            print("NO")
        else:
            print("YES")

    else:
        union(a,b)
