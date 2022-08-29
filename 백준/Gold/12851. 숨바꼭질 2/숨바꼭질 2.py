import sys
from collections import deque
input = sys.stdin.readline

s, e = map(int, input().split())

def bfs(x, t):
    cnt=0
    opt =  int(1e6)
    visited = [False for _ in range(100_001)]
    q = deque()
    q.append((x,t))
    visited[x] = True


    while q:
        pos, time= q.popleft()

        visited[pos] = True

        if opt < time:
            break
        if pos == e:
            opt = time
            cnt+=1
            continue
            
        if pos*2 - e <= abs(x-e) and pos*2 <=100000 and not visited[pos*2]:
            q.append((pos*2, time+1))

        if pos-1 >=0 and not visited[pos-1]:
            q.append((pos-1, time+1))

        if pos+1 <= 100000 and not visited[pos+1]:
            q.append((pos+1, time+1))
    print(opt)
    print(cnt)



bfs(s,0)