from collections import deque

n,m = map(int, input().split())

L = [[] for _ in range(n)]

for i in range(n):
    L[i] = list(input())

visited = [[False for _ in range(m)] for _ in range(n)]

def bfs(x, y):
    find_path = False
    queue = deque()
    queue.append((x,y,1))
    visited[x][y]=True

    while queue:
        a,b,length = queue.popleft()

        if a==n-1 and b==m-1:
            return length

        if a<n-1 and not visited[a+1][b] and L[a+1][b] == '1':
            queue.append((a+1,b,length+1))
            visited[a+1][b] = True

        if a>0 and not visited[a-1][b] and L[a-1][b] == '1':
            queue.append((a-1, b, length+1))
            visited[a-1][b] = True

        if b<m-1 and not visited[a][b+1] and L[a][b+1] == '1':
            queue.append((a, b+1, length+1))
            visited[a][b+1] = True

        if b>0 and not visited[a][b-1] and L[a][b-1] == '1':
            queue.append((a, b-1, length+1))
            visited[a][b-1] = True
    

print(bfs(0,0))     