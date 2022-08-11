from collections import deque


N = int(input())

queue = deque(range(1,N+1))

while len(queue) > 1:
    queue.popleft()
    a = queue.popleft()
    queue.append(a)

print(queue[0])