from collections import deque
import sys
input = sys.stdin.readline

def bfs(x, y):
    queue = deque()
    queue.append(x)
    cnt = 0

    while queue:
        cur = queue.popleft()

        if cur == y:
            cnt+=1
            continue

        if cur > y:
            continue

        queue.append(cur+1)
        queue.append(cur+2)
        queue.append(cur+3)

    return cnt
        
    
t = int(input())

for _ in range(t):
    n = int(input())
    print(bfs(0, n))