import sys, heapq
input = sys.stdin.readline
INF = int(1e9)

n, m, r = map(int, input().split())
Lt = list(map(int, input().split()))
Lt = [0]+Lt[:]

graph = [[] for _ in range(n+1)]

for _ in range(r):
    a,b,c = map(int, input().split())
    graph[a].append((b,c))
    graph[b].append((a,c))


def dijkstra(start):
    heap = []

    heapq.heappush(heap, (0,start))
    dist[start] = 0

    while heap:
        d, cur = heapq.heappop(heap)

        if dist[cur] < d:
            continue
        for i in graph[cur]:
            cost = d + i[1]

            if cost < dist[i[0]]:
                dist[i[0]] = cost
                heapq.heappush(heap, (cost, i[0]))

maxval = 0
for i in range(1,n+1):
    val = 0
    dist = [INF] * (n+1)
    dijkstra(i)
    for j in range(1, n+1):
        if dist[j] <= m:
            val+= Lt[j]

    if val > maxval:
        maxval = val

print(maxval)