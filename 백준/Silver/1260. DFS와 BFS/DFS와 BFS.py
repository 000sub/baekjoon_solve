from collections import deque
import sys

N, M, root = map(int, sys.stdin.readline().split())
edges = [[] for _ in range(N+1)]
queue = deque([root])
stack = deque([root])

for i in range(M):
    a,b = map(int, sys.stdin.readline().split())
    edges[a].append(b)
    edges[b].append(a)
    edges[a].sort()
    edges[b].sort()

visited = [False for _ in range(N+1)]

def dfs(node):
    visited[node] = True
    print(node, end = ' ')
    for i in edges[node]:
        if visited[i] == False:
            dfs(i)

dfs(root)
print()
visited = [False for _ in range(N+1)]
visited[root] = True

while len(queue) > 0:
    node = queue.popleft()
    print(node, end=' ')
    for n in edges[node]:
        if visited[n] == False:
            queue.append(n)
            visited[n] = True
