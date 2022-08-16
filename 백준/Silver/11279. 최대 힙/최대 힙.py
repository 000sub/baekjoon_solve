import heapq, sys
input = sys.stdin.readline

heap = []

N = int(input())

for _ in range(N):
    a = int(input())

    if a == 0:
        if not heap:
            print(0)
            continue
        else:
            print(-1 * heapq.heappop(heap))

    else:
        heapq.heappush(heap, -1*a)