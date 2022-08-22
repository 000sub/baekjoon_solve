import sys, heapq
input = sys.stdin.readline

T = int(input())
for _ in range(T):
    visited = [False for _ in range(1_000_000)]
    maxh, minh = [], []
    N = int(input())

    for i in range(N):
        op, num = input().split()
        num = int(num)

        

        if op == 'I':
            heapq.heappush(maxh, (-1*num,i))
            heapq.heappush(minh, (num,i))
            visited[i] = True

        else:
            if len(minh) < 1 or len(maxh) < 1:
                continue
            if num == -1:
                while len(minh)>0 and not visited[minh[0][1]]:
                    heapq.heappop(minh)
                if minh:
                    visited[minh[0][1]] = False
                    heapq.heappop(minh)

            else:
                while len(maxh)>0 and not visited[maxh[0][1]]:
                    heapq.heappop(maxh)
                if maxh:
                    visited[maxh[0][1]] = False
                    heapq.heappop(maxh)
                
    while len(maxh)>0 and not visited[maxh[0][1]]:
        heapq.heappop(maxh)
    while len(minh)>0 and not visited[minh[0][1]]:
        heapq.heappop(minh)

    if minh and maxh:
        print(-1*maxh[0][0], minh[0][0])
    else:
        print("EMPTY")