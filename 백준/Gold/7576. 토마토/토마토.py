from collections import deque
import copy

def check_complete():
    for i in range(N):
        for j in range(M):
            if box[i][j] == 0:
                return False
    return True


day = 0


M,N = map(int, input().split())
box = []
queue = deque()

for i in range(N):
    row = list(map(int, input().split()))
    box.append(row)

for i in range(N):
    for j in range(M):
        if box[i][j] == 1:
            queue.append((i,j))
            
day_seperator = copy.deepcopy(queue)

while len(queue) > 0:   
        if len(day_seperator) == 0:
            day+=1
            day_seperator = copy.deepcopy(queue)
        day_seperator.popleft()
        
        a, b = queue.popleft()
        
        if a>0:
            if box[a-1][b] == 0:
                box[a-1][b] = 1
                queue.append((a-1,b))
        if a<N-1:
            if box[a+1][b] == 0:
                box[a+1][b] = 1
                queue.append((a+1,b))
        if b<M-1:
            if box[a][b+1] == 0:
                box[a][b+1] = 1
                queue.append((a,b+1))
        if b>0:
            if box[a][b-1] == 0:
                box[a][b-1] = 1
                queue.append((a,b-1))   

if check_complete():
    print(day)
else:
    print(-1)