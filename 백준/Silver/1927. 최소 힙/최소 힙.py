import heapq,sys

N = int(sys.stdin.readline())

heap = []

for _ in range(N):
    a = int(sys.stdin.readline())

    if a == 0:
        if not heap:
            print(0)
        else:
            print(heapq.heappop(heap))

    else:
        heapq.heappush(heap, a)