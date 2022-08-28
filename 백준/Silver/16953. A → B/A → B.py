from collections import deque


a,b = map(int, input().split())
def bfs(x):
    queue = deque()

    queue.append((x, 1))
    
    while queue:
        cur, cnt = queue.popleft()

        if cur == b:
            return cnt

        if cur*10+1 <=b:
            queue.append((cur*10+1, cnt+1))

        if cur*2 <= b:
            queue.append((cur*2, cnt+1))

    return -1

print(bfs(a))