from collections import deque

N = int(input())
L = []

for _ in range(N):
    L.append(list(input()))

visited = [[False for _ in range(N)] for _ in range(N)]

def bfs(x,y):
    queue=deque()
    visited[x][y] = True
    queue.append((x,y))

    while queue:
        a,b = queue.popleft()

        #right
        if a<N-1 and not visited[a+1][b] and L[a][b] == L[a+1][b]:
            queue.append((a+1,b))
            visited[a+1][b] = True

        #left
        if a>0 and not visited[a-1][b] and L[a][b] == L[a-1][b]:
            queue.append((a-1,b))
            visited[a-1][b]= True

        #up
        if b>0 and not visited[a][b-1] and L[a][b] == L[a][b-1]:
            queue.append((a,b-1))
            visited[a][b-1]= True

        #down
        if b<N-1 and not visited[a][b+1] and L[a][b] == L[a][b+1]:
            queue.append((a,b+1))
            visited[a][b+1]= True
            
    for i in range(N):
        for j in range(N):
            if not visited[i][j]:
                return (i,j)
    return 0

cnt = 0
x, y = 0, 0
while True:
    ans = bfs(x,y)
    cnt+=1
    if type(ans) != int:
        x, y = ans
        continue
    else:
        ans1 = cnt
        break

for i in range(N):
    for j in range(N):
        if L[i][j] == 'G':
            L[i][j] = 'R'

cnt = 0
x, y = 0, 0
visited = [[False for _ in range(N)] for _ in range(N)]

while True:
    ans = bfs(x,y)
    cnt+=1
    if type(ans) != int:
        x, y = ans
        continue
    else:
        ans2 = cnt
        break

        
print(ans1, ans2)