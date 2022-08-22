import sys, heapq
input = sys.stdin.readline

N = int(input())
h = []

for _ in range(N):
    i = int(input())

    if i:
        if i < 0:
            heapq.heappush(h, (-i, -1))
        else:
            heapq.heappush(h, (i, 1))
    else:
        if h:
            val, inv = heapq.heappop(h)
            print(val*inv)
        else:
            print(0)