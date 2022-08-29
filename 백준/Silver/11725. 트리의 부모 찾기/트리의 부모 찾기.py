import sys
from collections import deque
input = sys.stdin.readline

n = int(input())
L=[[] for _ in range(n+1)]
visited = [False] * (n+1)

for _ in range(n-1):
    a,b = map(int,input().split())
    L[a].append(b)
    L[b].append(a)

def bfs(root):
    parent = [0] * (n+1)
    q = deque()
    q.append(root)
    visited[root] = True

    while q:
        cur = q.popleft()
        for node in L[cur]:
            if not visited[node]:
                parent[node] = cur
                visited[node] = True
                q.append(node)

    for i in range(2, n+1):
        print(parent[i])

bfs(1)