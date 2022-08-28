import sys, heapq
input = sys.stdin.readline
INF = int(1e9)

n, m = map(int, input().split())
s = int(input())
dist = [INF] * (n+1)
graph = [[] for _ in range(n+1)]


for _ in range(m):
    a,b,c = map(int, input().split())
    graph[a].append((b,c))


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


dijkstra(s)

for i in range(1, n+1):
    if dist[i] == INF:
        print('INF')
    else:
        print(dist[i])