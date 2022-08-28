import sys
input = sys.stdin.readline

n = int(input())
v = int(input())
L = [[] for _ in range(n+1)]
visited = []

for _ in range(v):
    a,b = map(int,input().split())
    L[a].append(b)
    L[b].append(a)

def dfs(x):
    visited.append(x)
    for node in L[x]:
        if node not in visited:
            dfs(node)

    return

dfs(1)
print(len(visited)-1)