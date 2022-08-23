from collections import deque

N = int(input())
L = [[] for _ in range(N)]


for i in range(N):
    L[i] = list(map(int, input().split()))

size = 2
eatcnt = 0

def bfs(x,y, move):
    visited = [[False for _ in range(N)] for _ in range(N)]
    global size, eatcnt
    queue = deque()
    queue.append((x,y,move))
    visited[x][y] = True

    
                
    if size == eatcnt:
        size+=1
        eatcnt = 0

    foods = []
    for i in range(N):
        for j in range(N):
            if L[i][j] and L[i][j]<size:
                foods.append((i,j))
    

    while queue:

        if queue: queue = deque(sorted(queue,key=lambda x: [x[2],x[0],x[1]]))
        a,b,cur = queue.popleft()

        #eatable
        if L[a][b] and L[a][b]<size:
            eatcnt+=1
            return a,b, cur

        #up
        if a>0 and not visited[a-1][b] and L[a-1][b]<=size:
            visited[a-1][b] = True
            queue.append((a-1, b,cur+1))


        #left
        if b>0 and not visited[a][b-1] and L[a][b-1]<=size:
            visited[a][b-1] = True
            queue.append((a,b-1,cur+1))

        
        #down
        if a<N-1 and not visited[a+1][b] and L[a+1][b]<=size:
            visited[a+1][b] = True
            queue.append((a+1,b,cur+1))
        #right
        if b<N-1 and not visited[a][b+1] and L[a][b+1]<=size:
            visited[a][b+1] = True
            queue.append((a,b+1,cur+1))

    return -1,-1,-1

for i in range(N):
    for j in range(N):
        if L[i][j] == 9:
            posx, posy = i,j
            break
globmove = 0
while globmove!=-1:
    prev = globmove
    L[posx][posy]=0
    posx, posy, globmove = bfs(posx, posy, globmove)
    L[posx][posy] = 9


print(prev)