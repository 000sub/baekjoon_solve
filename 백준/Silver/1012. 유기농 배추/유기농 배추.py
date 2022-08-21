import sys
from collections import deque
input = sys.stdin.readline

def bfs(x,y):
    queue = deque()
    queue.append((x,y))
    visited[x][y] = True

    while queue:
        a,b = queue.popleft()

        if a>0 and not visited[a-1][b] and L[a-1][b] == 1:
            queue.append((a-1,b))
            visited[a-1][b] = True

        if a<m-1 and not visited[a+1][b] and L[a+1][b] == 1:
            queue.append((a+1,b))
            visited[a+1][b] = True

        if b>0 and not visited[a][b-1] and L[a][b-1] == 1:
            queue.append((a,b-1))
            visited[a][b-1] = True

        if b<n-1 and not visited[a][b+1] and L[a][b+1] == 1:
            queue.append((a,b+1))
            visited[a][b+1] = True

    for i in range(m):
        for j in range(n):
            if L[i][j] == 1 and not visited[i][j]:
                return 1+bfs(i,j)

    return 1
        
    
T = int(input())

for _ in range(T):
    m,n,k = map(int, input().split())
    L = [[0 for _ in range(n)] for _ in range(m)]
    visited = [[False for _ in range(n)] for _ in range(m)]
    

    for _ in range(k):
        i,j = map(int, input().split())
        L[i][j] = 1

    for i in range(m):
        for j in range(n):
            if L[i][j] ==1:
                st_x, st_y = i,j

    print(bfs(st_x, st_y))