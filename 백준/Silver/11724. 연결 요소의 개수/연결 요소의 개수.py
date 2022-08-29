import sys
input = sys.stdin.readline
sys.setrecursionlimit(1000000)


n,m = map(int, input().split())
L=[[] for _ in range(n+1)]
visited = [False for _ in range(n+1)]
for _ in range(m):
    a,b = map(int, input().split())
    L[a].append(b)
    L[b].append(a)


def dfs(x):
    visited[x] = True
    for node in L[x]:
        if not visited[node]:
            dfs(node)


cnt=0

while True:
    for i in range(1,n+1):
        if not visited[i]:
            dfs(i)
            cnt+=1
    break

print(cnt)