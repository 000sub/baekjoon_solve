from collections import deque
import sys
input = sys.stdin.readline

def bfs(x, y):
    queue = deque()
    visited = [False for _ in range(10000)]
    queue.append((x, ""))
    visited[x] = True

    while queue:
        a, cur= queue.popleft()

        #reach target
        if a == y:
            return cur

        #D
        op_d = a*2%10000
        if not visited[op_d]:
            queue.append((op_d,cur+'D'))
            visited[op_d] = True

        #S
        op_s = a-1 if a else 9999

        if not visited[op_s]:
            queue.append((op_s,cur+'S'))
            visited[op_s] = True

        #L
        op_l = a//1000+(a%1000//100)*1000+(a%100//10)*100+(a%10)*10

        if not visited[op_l]:
            queue.append((op_l, cur+'L'))
            visited[op_l] = True

        #R
        op_r = (a%10)*1000 + (a//1000)*100 + (a%1000//100)*10 + (a%100//10)

        if not visited[op_r]:
            queue.append((op_r, cur+'R'))
            visited[op_r] = True
    
T = int(input())

for _ in range(T):
    start,end = map(int, input().split())

    print(bfs(start, end))

    
