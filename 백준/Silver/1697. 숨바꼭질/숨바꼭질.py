from collections import deque

n, k = map(int, input().split())


queue = deque()
queue.append((n, 0))
visited = [0 for _ in range(100_001)]
while queue:
    num, sec = queue.popleft()

    if num == k:
        print(sec)
        break

    if num*2 <= 100_000 and not visited[num*2]:
        visited[num*2] = True
        queue.append((num*2, sec+1))

    if num+1 <= 100_000 and not visited[num+1]:
        visited[num+1] = True
        queue.append((num+1, sec+1))

    if num-1 >= 0 and not visited[num-1]:
        visited[num-1] = True
        queue.append((num-1, sec+1))
